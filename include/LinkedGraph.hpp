#ifndef LINKEDGR
#define LINKEDGR

#include <vector>
#include <cstdbool>
#include <fstream>
#include <random>
#include <limits>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#include "helper.hpp"
#include "Path.hpp"

/**
 * \class LinkedGraph
 * \brief Basic structure for graph construction according to a vector that stores vertex, which in turn stores edges in lists.
 * The data structure of a linked graph is useful in sparse graphs, which don't hava lots of edges. The conception of this graph
 * is of directioned graph that can have weak connections of even unconnected subgraphs.
 * \author: jhosoume
 * \date: 2018/08/26 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
template <typename T> // Template for class and node LinkedGraph. Needs to be outside since the compiler
                      // needs to know the size of the data to be provided.
                      // The following class has all the definitions of methods that should be on
                      // the .cpp, because the template requires the implementation followed by the
                      // definition.
class LinkedGraph {
public:
    /* ___________________________ CONSTRUCTORS AND DESTRUCTOR __________________________*/
    /**
     * LinkedGraph constructor.
     * Defines default values for the basic attributes.
     * @param numVert indicates the number of vertices (Vertex) of the graph.
     * @param numEdg indicates the number of edges (Edge) of the graph.
     * @param nodes pass the array that stores all the graph vertices and their edges.
     * @return The complete LinkedGraph with its vertices (Vertex) and edges (Edge)
     */
    LinkedGraph(size_t numVert, size_t numEdg, std::vector< Vertex<T> > nodes)
    : numVertex{numVert}, numEdges{numEdg}, allVertex{nodes}
    {}

    /**
     * LinkedGraph constructor.
     * Defines default values for the basic attributes. Initializing the graph without vertices (Vertex) or edges (Edge).
     * @return The complete LinkedGraph with its stats zeroed
     */
    LinkedGraph()
    : numVertex{0}, numEdges{0}, allVertex()
    {}

    /**
     * LinkedGraph destructor.
     * Releases not only the space of the current graph, but also its Vertex and Edges.
     */
    // ~LinkedGraph() {
    //     for (Vertex<T> *item : allVertex) {
    //         delete item;
    //     }
    // }
    /* ______________________END OF CONSTRUCTORS AND DESTRUCTOR __________________________*/

   /**
    * Auxiliary function to check if there is already an edge that connects two given vertices.
    * @param src_pos Position of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest_pos Position of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @return A boolean according to the existence (true) or inexistence (false) of the Edge.
    */
   bool has_edge(size_t src_pos, size_t dest_pos, bool print = false) {
       // Print for debugging purpouses
       if (print)
           std::cout << "Checando se já existe aresta de " << src_pos << " até " << dest_pos << std::endl;
       // If it has no neighbours there is no need to ask if there is an edge.
       if (!allVertex.at(src_pos).has_neighbours()) {
           if (print)
                std::cout << "Grafo não possui essa aresta ainda!\n" << std::endl;
            return false;
       // Loop throught all the edges trying to find if the given edge is already defined
       } else {
            for (Edge vert : allVertex.at(src_pos).ownEdges) {
                if (vert.get_dest() == dest_pos) {
                    if (print)
                        std::cout << "Grafo já possui essa aresta!\n" << std::endl;
                    return true;
                }
            }
        }
       return false;
   }

   /**
    * Auxiliary function to check if there is already an edge that connects two given vertices.
    * @param src_pos Position of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest_pos Position of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @return A boolean according to the existence (true) or inexistence (false) of the Edge.
    */
   bool has_edge(T src, T dest, bool print = false) {
       size_t src_pos = -1, dest_pos = -1;
       if (allVertex.size() == 0) {
           if (print)
                std::cout << "Grafo não possui vertices!\n" << std::endl;
            return false;
        }
        // Looking for the positions of source and destinations
       for (auto vert : allVertex) {
           if (vert.get_id() == src)
                src_pos = vert.get_pos();
           if (vert.get_id() == dest)
                dest_pos = vert.get_pos();
       }
       // Return error if vertices were not found
       if (src_pos == -1 || dest_pos == -1) {
           if (print)
                std::cout << "Vertices indicados não encontrados!\n" << std::endl;
            return false;
       }
       // If it has no neighbours there is no need to ask if there is an edge.
       if (!allVertex.at(src_pos).has_neighbours()) {
           if (print)
                std::cout << "Grafo não possui essa aresta ainda!\n" << std::endl;
            return false;
       // Loop throught all the edges trying to find if the given edge is already defined
       } else {
            for (Edge vert : allVertex.at(src_pos).ownEdges) {
                if (vert.get_dest() == dest_pos) {
                    if (print)
                        std::cout << "Grafo já possui essa aresta!\n" << std::endl;
                    return true;
                }
            }
        }
       return false;
   }

   /**
    * Auxiliary function to insert a Vertex in the LinkedGraph vector of vertices.
    * @param value Identification of the Vertex to be inserted.
    * @return Nothing, but the LinkedGraph is altered
    */
    void insertVertex(T value) {
        numVertex++;
        // Creates a new Vertex in the heap.
        Vertex<T> aux = Vertex<T>(value, numVertex - 1);
        allVertex.push_back(aux);
        if ( numVertex < 0 || numVertex > allVertex.size())
            // Throws an error if the alloc was not properly done.
            throw std::out_of_range("There is a problem Houston! Please check the numVertex attribute from the Linked Graph!\n");
        return;
   }

   /**
    * Auxiliary function to insert a Bidirected Edge (as in a non directed graph) in the LinkedGraph vector of vertices.
    * @param src_pos Position of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest_pos Position of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @param weight Cost to traverse the given edge in both directions.
    * @return Nothing, but the vertices (source and destination Vertex) of the LinkedGraph are altered
    */
   void insertBiDirEdges(size_t src_pos, size_t dest_pos, float weight) {
       // Checking if the numbers are correct.
       if (allVertex.size() == 0)
            throw std::out_of_range("There is a problem Houston! There isn't any vertex in the graph :O\n");
       if (src_pos < 0 || dest_pos < 0 || src_pos > numVertex || dest_pos > numVertex)
            throw std::out_of_range("There is a problem Houston! Please enter a correct reference for source and destination positions!\n");
       if (has_edge(src_pos, dest_pos)) {
           std::cout << "There is already an edge connecting these two vertices\n";
           return;
        }
        // Create both edges and allocate them
       Edge aux = Edge(dest_pos, weight);
       allVertex.at(src_pos).ownEdges.push_front(aux);
       allVertex.at(dest_pos).parents.push_front(src_pos);
       numEdges++;
       // If there is already an edge don't perform the insertion
       if (!has_edge(dest_pos, src_pos)) {
           Edge aux2 = Edge(src_pos, weight);
           allVertex.at(dest_pos).ownEdges.push_front(aux2);
           numEdges++;
        }
       return;
   }

   /**
    * Auxiliary function to insert an Edge (as in a directed graph) in the LinkedGraph vector of vertices.
    * @param src_pos Position of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest_pos Position of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @param weight Cost to traverse the given edge in both directions.
    * @return Nothing, but the vertex (source Vertex) of the LinkedGraph is altered
    */
   void insertEdge(size_t src_pos, size_t dest_pos, float weight) {
       if (allVertex.size() == 0)
            throw std::out_of_range("There is a problem Houston! There isn't any vertex in the graph :O\n");
       if (src_pos < 0 || dest_pos < 0 || src_pos > numVertex || dest_pos > numVertex)
            throw std::out_of_range("There is a problem Houston! Please enter a correct reference for source and destination positions!\n");
       if (has_edge(src_pos, dest_pos)) {
           std::cout << "There is already an edge connecting these two vertices\n";
           return;
        }
        // Insert Edge and deals with the parent case (include the position of the parent in the list of parents)
       Edge aux = Edge(dest_pos, weight);
       allVertex[src_pos].ownEdges.push_front(aux);
       allVertex[dest_pos].parents.push_front(src_pos);
       //std::cout << "Vertex " <<  dest_pos << " has parents " << allVertex[dest_pos]->parents.size() << std::endl;
       numEdges++;
       return;
   }

   /**
    * Auxiliary function to insert an Edge (as in a directed graph) in the LinkedGraph vector of vertices,
    * according to the identifications of source and destination and not from the absolute positions.
    * @param src Identification of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest Identification of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @param weight Cost to traverse the given edge in both directions.
    * @return Nothing, but the vertex (source Vertex) of the LinkedGraph is altered
    */
   void insertConnection(T src, T dest, float weight) {
       //TODO Check if the map isn't faster!
       size_t src_pos = -1, dest_pos = -1;
       if (allVertex.size() == 0)
            throw std::out_of_range("There is a problem Houston! There isn't any vertex in the graph :O\n");
        // Looking for the positions of source and destinations
       for (auto vert : allVertex) {
           if (vert.get_id() == src)
                src_pos = vert.get_pos();
           if (vert.get_id() == dest)
                dest_pos = vert.get_pos();
       }
       // If the id wasn't located
       if (src_pos == -1 || dest_pos == -1)
           throw std::logic_error("There isn't a source or destination with this especification\n");
       if (has_edge(src_pos, dest_pos)) {
           std::cout << "There is already an edge connecting these two vertices\n";
           return;
        }
        // Creating and inserting edge
       Edge aux = Edge(dest_pos, weight);
       allVertex.at(src_pos).ownEdges.push_front(aux);
       allVertex.at(dest_pos).parents.push_front(src_pos);
       numEdges++;
       return;
   }

   /**
    * Auxiliary function to insert an Edge (as in a non directed graph) in the LinkedGraph vector of vertices,
    * according to the identifications of source and destination and not from the absolute positions.
    * @param src Identification of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest Identification of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @param weight Cost to traverse the given edge in both directions.
    * @return Nothing, but the vertex (source Vertex) of the LinkedGraph is altered
    */
   void insertNondirectedConnection(T src, T dest, float weight) {
       //TODO Check if the map isn't faster!
       size_t src_pos = -1, dest_pos = -1;
       if (allVertex.size() == 0)
            throw std::out_of_range("There is a problem Houston! There isn't any vertex in the graph :O\n");
        // Looking for the positions of source and destinations
       for (auto vert : allVertex) {
           if (vert.get_id() == src)
                src_pos = vert.get_pos();
           if (vert.get_id() == dest)
                dest_pos = vert.get_pos();
       }
       // If the id wasn't located
       if (src_pos == -1 || dest_pos == -1)
           throw std::logic_error("There isn't a source or destination with this especification\n");
       if (has_edge(src_pos, dest_pos)) {
           std::cout << "There is already an edge connecting these two vertices\n";
           return;
        }
        // Creating and inserting edge
       Edge aux = Edge(dest_pos, weight);
       allVertex.at(src_pos).ownEdges.push_front(aux);
       allVertex.at(dest_pos).parents.push_front(src_pos);
       aux = Edge(src_pos, weight);
       if (!has_edge(dest_pos, src_pos)) {
           allVertex.at(dest_pos).ownEdges.push_front(aux);
           allVertex.at(src_pos).parents.push_front(dest_pos);
        }
       numEdges++;
       return;
   }

   /**
    * Auxiliary function to insert an Edge (as in a non directed graph) in the LinkedGraph vector of vertices,
    * according to the identifications from the absolute positions.
    * @param src_pos Position of the source Vertex on the vector of vertices of the LinkedGraph.
    * @param dest_pos Position of the destination Vertex on the vector of vertices of the LinkedGraph.
    * @param weight Cost to traverse the given edge in both directions.
    * @return Nothing, but the vertex (source Vertex) of the LinkedGraph is altered
    */
   void insertNondirectedEdge(size_t src_pos, size_t dest_pos, float weight) {
       if (allVertex.size() == 0)
            throw std::out_of_range("There is a problem Houston! There isn't any vertex in the graph :O\n");
       if (src_pos < 0 || dest_pos < 0 || src_pos > numVertex || dest_pos > numVertex)
            throw std::out_of_range("There is a problem Houston! Please enter a correct reference for source and destination positions!\n");
       if (has_edge(src_pos, dest_pos)) {
           std::cout << "There is already an edge connecting these two vertices\n";
           return;
        }
        // Creating and inserting edge
       Edge aux = Edge(dest_pos, weight);
       allVertex.at(src_pos).ownEdges.push_front(aux);
       allVertex.at(dest_pos).parents.push_front(src_pos);
       aux = Edge(src_pos, weight);
       if (!has_edge(dest_pos, src_pos)) {
           allVertex.at(dest_pos).ownEdges.push_front(aux);
           allVertex.at(src_pos).parents.push_front(dest_pos);
        }
       numEdges++;
       return;
   }

    /**
     * Auxiliary function to obtain the number of vertices (Vertex) on the allVertex vector.
     * Function to provide help in retriving the information about the total number of vertices (Vertex) on the LinkedGraph.
     * @return An unsigned integer indicating the total number of vertices.
     */
   size_t num_vertices() {
       if (numVertex != allVertex.size())
           // Just to make sure that the number holded by the graph is corresponding to the total size of the vector of vertices.
           std::cerr << "There is a problem Houston! The vector that contains the vertices has not the same lenght as the stored numver!\n";
       return numVertex;
   }

    /**
     * Auxiliary function to obtain the number of edges (Edge) on the LinkedGraph.
     * Function to provide help in retriving the information about the total number of edges (Edge) on the LinkedGraph, considering all the edges holded by all the vertices (Vertex) on the graph.
     * @return An unsigned integer indicating the total number of edges.
     */
   size_t num_edges() {
       return numEdges;
   }

    /**
     * Auxiliary function to print the LinkedGraph structure.
     * Function to provide help in retriving the information (printing on the screen) about all the vertices (Vertex) and its edges (Edge).
     * @return Nothing, but prints all the vertices and its edges
     */
   void print() {
       std::cout << "\n\nVertex -> Edges\n";
       std::cout << "---------------------------------------\n";
       // Making a loop to retrive the information to be printed.
       // All the vertices are visited.
       for (Vertex<T> vet : allVertex) {
           // if (vet == nullptr)
           //     std::cerr << "There is a problem Houston! One of the Vertex is missing!" << std::endl;
           std::cout << " * " << vet.get_id();
           if (!vet.has_neighbours())
               std::cout << " None!";
           else {
               for (auto neigh : vet.ownEdges)
                   std::cout << " -> " << "| " <<  allVertex.at(neigh.get_dest()).get_id() <<  ", " <<  neigh.get_weight() << " | ";
           }
           std::cout << "\n";
       }
       std::cout << "---------------------------------------\n";
       return;
   }

   void writeDigraphAsDot(std::string name, std::string file) {
       std::ofstream outfile;
       outfile.open(file, std::ios::out);
       outfile << "digraph " << name << " {" << std::endl;
       for (Vertex<T> vert : allVertex) {
           outfile << vert.get_id() << " ;" << std::endl;
       }
       for (Vertex<T> vert : allVertex) {
           if (vert.has_neighbours()) {
               for (auto edge : vert.ownEdges) {
                   outfile << vert.get_id() << " -> "
                             << allVertex.at(edge.get_dest()).get_id()
                             << " [label = " << edge.get_weight() << "] ;"
                             << std::endl;
                }
           }
       }
       outfile << "}" << std::endl;
       outfile.close();
   }

   void writeCPMAsDot(std::string name, std::string file,
                      std::vector<Edge> edges_colored,
                      std::string color = "red"
                     ) {
       std::ofstream outfile;
       outfile.open(file, std::ios::out);
       outfile << "digraph " << name << " {" << std::endl;
       for (Vertex<T> vert : allVertex) {
           outfile << vert.get_id() << " ;" << std::endl;
       }
       for (Vertex<T> vert : allVertex) {
           if (vert.has_neighbours()) {
               for (auto edge : vert.ownEdges) {
                   outfile << vert.get_id() << " -> "
                             << allVertex.at(edge.get_dest()).get_id()
                             << " [label = " << edge.get_weight();
                    if (std::find(edges_colored.begin(), edges_colored.end(), edge) != edges_colored.end()) {
                        outfile << ", color = " << color;
                    }
                    outfile << " ] ;" << std::endl;
                }
           }
       }
       outfile << "}" << std::endl;
       outfile.close();
   }

/**
 * Perform a Depth First Search in the graph from a given source.
 * Encapsulates a recursive function that traverse each connected graph only once. It only goes through the directional edges (Edge) from the given Vertex position, does not visit the parents, so if the graph is constituted of many subgraphs, this function does not goes throught all of them. Depends on the walkDFS() function.
 * @param source The position of the Vertex from where the traverse is originated.
 * @return Does not return a value, but prints the trajectory.
 */
void DFS(size_t source) {
    marks = std::vector<bool>(numVertex, false);
    Vertex<T> src_vert = allVertex[source];
    // Check if the pointer isn't null
    if (!src_vert.has_neighbours()) {
        std::cout << "The given source has no neighbours!" << std::endl;
        return;
    } else{
        // Prints and call the recursive function.
        std::cout << "\nStarted Dept First Search from graph position " << source << " identification " << src_vert.get_id() << std::endl;
        walkDFS(source);
    }
    return;
}

/**
 * Perform a traverse to search for all connected vertices (Vertex) and prints the groups.
 * Traverso to all connected pathways, parents and neighbours, to find the connected groups and prints the subgraphs (non connected groups of vertices). Very similar to DFS, nonetheless takes the parents into account too.
 * @return Does not returns a value, but prints all the subgraphs.
 */
void findConnected() {
    marks = std::vector<bool>(numVertex, false);
    // Search for all Vertex
    for (size_t i = 0; i< numVertex; i++) {
        // Only visits the ones not previously checked
        if (!marks[i]) {
            // Creates a new group;
            std::list<size_t> group;
            // Recursivily visits all the connected vertices to this vertex
            walkConnected(i, group);
            // Includes the given group to the holder of all groups
            groups.push_back(group);
            // Empty the group to restart
            group.clear();
        }
    }
    // Printing the graph subgraphs after collection of data
    size_t nGroup = 0;
    for (auto group : groups) {
        std::cout << "Group " << nGroup << " has members: " << std::endl;
        for (auto member : group) {
            std::cout << "Member position " << member << " of identification " << allVertex[member].get_id() << std::endl;
        }
        nGroup++;
        std::cout << std::endl;
    }
}
    /**
     * Floyd-Warshall algorithm to perform search for the minimum pathway.
     * This algorithm takes into consideration the intermediate steps, so it includes a vertex in the path and checks if
     * this step shortens the path, if so it is now considered as the minimum. Unfortunately, for this algorithm a matrix
     * of size number of vertices x number of vertices is constructed, nevertheless this matrix is also used to store the
     * information.
     * @return Does not return a value, but prints all the minimal pathways from all the vertices.
     */
    std::vector<std::vector<float> > FloydWarshall() {
        // Initiate the matrix that holds the distances (weight) from all the vertices (Vertex), and finally all the
        // minimum pathways.
        std::vector<std::vector<float> > distances = distanceMatrix();
        // Loops to compare all the pathways considering the intermidiate vertices
        for (size_t k = 0; k < num_vertices(); k++)
            for (size_t i = 0; i < num_vertices(); i++)
                for (size_t j = 0; j < num_vertices(); j++)
                    if (distances[i][j] > distances[i][k] + distances[k][j])
                        distances[i][j] = distances[i][k] + distances[k][j];
        // Printing out the matrix with the results
        std::cout << "__________Starting Floyd Warshall results! ________" << std::endl;
        for (size_t i = 0; i < num_vertices(); i++) {
            std::cout << " *The minimul pathway from position " << i << " of id " << allVertex[i].get_id() << " to: "<<  std::endl;
            for (size_t j = 0; j < num_vertices(); j++) {
                std::cout << "--> Vertex " << j << " of id " << allVertex[j].get_id() << " is "<< distances[i][j] <<  std::endl;
            }
        }
        return distances;
    }

     /**
     * Max Floyd-Warshall algorithm altered to perform search for the longest pathway.
     * This algorithm takes into consideration the intermediate steps, so it includes a vertex in the path and checks if
     * this step shortens the path, if so it is now considered as the minimum. Unfortunately, for this algorithm a matrix
     * of size number of vertices x number of vertices is constructed, nevertheless this matrix is also used to store the
     * information.
     * @return Does not return a value, but prints all the minimal pathways from all the vertices.
     */
    std::vector<std::vector<float> > LongestFloydWarshall() {
        // Initiate the matrix that holds the distances (weight) from all the vertices (Vertex), and finally all the
        // minimum pathways.
        float inf = std::numeric_limits<float>::infinity();
        std::vector<std::vector<float> > distances = maxDistanceMatrix();
        nextVertPos = nextInMaxPath();
        // Loops to compare all the pathways considering the intermidiate vertices
        for (size_t k = 0; k < num_vertices(); k++)
            for (size_t i = 0; i < num_vertices(); i++)
                for (size_t j = 0; j < num_vertices(); j++) {
                    if (distances.at(i).at(j) > distances.at(i).at(k) + distances.at(k).at(j)) {
                        distances.at(i).at(j) = distances.at(i).at(k) + distances.at(k).at(j);
                        nextVertPos.at(i).at(j) = nextVertPos.at(i).at(k);
                    }
                }


        // Printing out the matrix with the results
        // std::cout << "__________Starting Floyd Warshall results! ________" << std::endl;
        for (size_t i = 0; i < num_vertices(); i++) {
            // std::cout << " *The longest pathway from position " << i << " of id " << allVertex[i].get_id() << " to: "<<  std::endl;
            for (size_t j = 0; j < num_vertices(); j++) {
                if (distances.at(i).at(j) != 0 && distances.at(i).at(j) != inf) {
                    distances.at(i).at(j) *= -1;
                }
                // std::cout << "--> Vertex " << j << " of id " << allVertex[j].get_id() << " is "<< distances[i][j] <<  std::endl;
            }
        }
        return distances;
    }

    void CriticalPath(int num_paths) {
        float inf = std::numeric_limits<float>::infinity();
        std::vector< Path > paths;
        std::vector<std::vector <float>> distances = LongestFloydWarshall();
        float distance;
        std::vector <int> full_path;
        Path long_path;
        int src, dest;
        Edge edge;
        std::vector <Edge> path_edges;
        for (int src = 0; src < num_vertices(); ++src) {
            for (int dest = 0; dest < num_vertices(); ++dest) {
                distance = distances.at(src).at(dest);
                if (distance != 0 && distance != inf)
                    paths.push_back(Path(src, dest, distance));
            }
        }
        std::sort(paths.begin(), paths.end(), pathComparator);
        std::cout << "--------------------------------" << std::endl;
        std::cout << "The " << num_paths << " longest paths in the graph are: " << std::endl;
        for(int indx = 1; indx < num_paths + 1; ++indx) {
            long_path = paths.at(paths.size() - indx);
            src = long_path.src; dest = long_path.dest;
            full_path = path(long_path.src, long_path.dest);
            std::cout << indx << ". "
                      << allVertex.at(src).get_id()
                      << " to " << allVertex.at(dest).get_id()
                      << " | Total cost: " << long_path.cost
                      << std::endl;
            std::cout << "      Total Path in topological order: " << std::endl;
            for (int indx = 0; indx < full_path.size(); ++indx) {
                std::cout << allVertex.at(full_path.at(indx)).get_id();
                if (indx + 1 < full_path.size()) {
                    edge = allVertex.at(full_path.at(indx)).getEdgeToNeighbor(full_path.at(indx + 1));
                    path_edges.push_back(edge);
                    std::cout << " - " << edge.get_weight() << " - > " ;

                } else {
                    std::cout << std::endl;
                }
            }
        }
        Path longest_path = paths.at(paths.size() - 1);
        std::vector <int> full_longest_path = path(longest_path.src, longest_path.dest);
        std::vector <Edge> longest_path_edges;
        for (int indx = 0; indx < full_longest_path.size(); ++indx) {
            if (indx + 1 < full_longest_path.size()) {
                edge = allVertex.at(full_longest_path.at(indx)).getEdgeToNeighbor(full_longest_path.at(indx + 1));
                longest_path_edges.push_back(edge);
            }
        }
        writeCPMAsDot("first_critical_path", "first_critical_path.dot",
                       longest_path_edges, "blue");
        std::cout << "--------------------------------" << std::endl;
        std::cout << "The second longest with different nodes is " << std::endl;
        for(int indx = 1; indx < num_paths + 1; ++indx) {
            long_path = paths.at(paths.size() - indx);
        }
        std::cout << "--------------------------------" << std::endl;
    }

    std::vector<int> path(int src, int dest) {
        std::vector<int> verticiesInPath;
        int next = src;
        if (nextVertPos[src][dest] == -1) {
            return verticiesInPath;
        }
        verticiesInPath.push_back(src);
        while (next != dest) {
            next = nextVertPos[next][dest];
            verticiesInPath.push_back(next);
        }
        return verticiesInPath;
    }


    /**
     * Bron-Kerbosch algorithm to perform search for all the maximal cliques.
     * @return Does not return a value, but prints all the maximais cliques.
     */
    void BronKerbosch() const {
        std::set<int> R, X; // R and X are empty sets
        std::set<int> P = getSetAllPositions(); // P is the set of all verticies
        recursiveBronKerbosch(R, P, X);
    }

    std::vector < Vertex<T> > getVertices() const {
      return allVertex;
    }

    std::set<int> getSetAllPositions() const {
        std::set<int> all_pos;
        for(int indx = 0; indx < allVertex.size(); ++indx) {
            all_pos.insert(indx);
        }
        return all_pos;
    }

    /**
     * Auxiliary function to print the clustering coefficient of all verticies
     * @return Does not return a value, but prints all clustering coefficients.
     */
    void printVerticiesClusteringCoeff() const {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Printing Verticies Coefficients" << std::endl;
        std::cout << "Vertex Data := Clustering Coefficient" << std::endl;
        for (Vertex<T> vert : allVertex) {
            std::cout << vert.get_id() << " := " << ClusteringCoeff(vert) << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }

    /**
     * Auxiliary function to calculate the mean of all the clustering coefficients
     * @return The mean clustering coefficient.
     */
    double MeanClusteringCoeff() const {
        double total = 0;
        for (Vertex<T> vert : allVertex) {
            total += ClusteringCoeff(vert);
        }
        return total / numVertex;

    }

    void printTopologicalOrder(std::string name, std::string file) const {
        std::vector <Vertex <T> > topOrder = Kahn();
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "One of the possible Topological Order" << std::endl;
        for (int indx = 0; indx < topOrder.size(); ++indx) {
            std::cout << indx + 1 << " : " << topOrder.at(indx).get_id() << std::endl;
        }
        std::cout << "---------------------------------------" << std::endl;

        std::ofstream outfile;
        outfile.open(file, std::ios::out);
        outfile << "digraph " << name << " {" << std::endl;
        outfile << "graph [ordering = \"out\"]" << std::endl;
        for (Vertex<T> vert : topOrder) {
            outfile << vert.get_id() << " ;" << std::endl;
        }
        outfile << "{rank = same;" << std::endl;
        for (Vertex<T> vert : topOrder) {
            outfile << vert.get_id() << " ;" << std::endl;
        }
        outfile << "}" << std::endl;
        for (Vertex<T> vert : allVertex) {
            if (vert.has_neighbours()) {
               for (auto edge : vert.ownEdges) {
                   outfile << vert.get_id() << " -> "
                             << allVertex.at(edge.get_dest()).get_id()
                             << " [label = " << edge.get_weight() << "]"
                             << " ;" << std::endl;
                }
           }
       }
       outfile << "}" << std::endl;
       outfile.close();
    }


private:
    size_t numVertex; ///< total number of vertices (Vertex) cointained in the LinkedGraph and stored in allVertex
    size_t numEdges; ///< total number of edges (Edge) stored in the contained vertices (Vertex)
    std::vector< Vertex<T> > allVertex; ///< Vector (std::vector) that stores pointers to all the vertices (Vertex) bound to the graph (LinkedGraph)
    std::vector<bool> marks; ///< Vector that maps all the vertices that was traversed during DFS or for checking connected components
    std::list<std::list<size_t> > groups; ///< Stores the subgraphs that composes the LinkedGraph
    std::vector < std::vector < int > > nextVertPos; // Store the position of the next vertex to go in the longest pathway

    /**
     * Creates a distance matrix according to the LinkedGraph vertices and edges
     * @return A bidimensional matrix of size number of vertices x number of vertices with the cost of traversing the edges that connects them.
     */
    std::vector<std::vector<float>> distanceMatrix() {
        // Get the maximum number to represent the infinity (cant traverse the edge at all, so the edge does not exist)
        float inf = std::numeric_limits<float>::infinity();
        // creates the edge, maybe it should then be created as a "new" container to further increase its capacity!
        std::vector<std::vector<float>> distances(num_vertices(), std::vector<float>(num_vertices(), inf));
        // put all the information of the edges in the matrix
        for (auto vec : allVertex) {
            size_t pos = vec.get_pos();
            distances[pos][pos] = 0;
            if (vec.has_neighbours())
                for (auto next : vec.ownEdges)
                    distances[pos][next.get_dest()] = next.get_weight();

        }
        return distances;
    }

    std::vector <std::vector < float > > maxDistanceMatrix() {
        // Get the maximum number to represent the infinity (cant traverse the edge at all, so the edge does not exist)
        float inf = std::numeric_limits<float>::infinity();
        // creates the edge, maybe it should then be created as a "new" container to further increase its capacity!
        std::vector<std::vector<float>> distances(num_vertices(), std::vector<float>(num_vertices(), inf));
        // put all the information of the edges in the matrix
        for (auto vec : allVertex) {
            size_t pos = vec.get_pos();
            distances[pos][pos] = 0;
            if (vec.has_neighbours())
                for (auto next : vec.ownEdges)
                    distances[pos][next.get_dest()] = -next.get_weight();
        }
        return distances;
    }

    std::vector <std::vector < int > > nextInMaxPath() {
        std::vector<std::vector<int>> nextPos(num_vertices(), std::vector<int>(num_vertices(), -1));
        for (auto vec : allVertex) {
            size_t pos = vec.get_pos();
            nextPos[pos][pos] = pos;
            if (vec.has_neighbours())
                for (Edge edge : vec.ownEdges)
                    nextPos[pos][edge.get_dest()] = edge.get_dest();
        }
        return nextPos;
    }

    /**
     * Auxiliary function to print to the screen the verticies specified
     * in a set of positions.
     * @param positions set of all verticies to be printed
     * @return does not return a value, but prints the set
     */
    void printFromSet(std::set<int> positions) const {
        std::cout << "[ ";
        for (int pos : positions) {
            std::cout << allVertex.at(pos).get_id() << " ";
        }
        std::cout << " ] " << std::endl;
    }

    /**
     * Recursive function that traverses from the sorce Vertex to all its children and the children of their children.
     * @param pos position of the source Vertex.
     * @return does not return a value, but prints its path
     */
    void walkDFS(size_t pos){
        // Setting for the recursion
        std::list< Edge > aux;
        // The Vertex was already checked as having neighbours
        std::list< Edge > hold = allVertex[pos].ownEdges;
        size_t next_pos;
        // Marking the Vertex as traversed
        marks[pos] = true;
        aux = hold;
        // Goes throught the children of the Vertex
        for (auto edge : aux) {
            next_pos = edge.get_dest();
            // If the Vertex wasn't marked, visit
            if (!marks[next_pos]) {
                std::cout << "DFS :: Next Vertex is position " << next_pos << " identification " << allVertex[next_pos].get_id() << std::endl;
                // Calls the function again for the children of the child
                walkDFS(next_pos);
            }
        }
    }

    /**
     * Similar to walkDFS(), goes recursively to all the parents of the parents and the children of the children, collecting them to constitute the connected group.
     * @param pos position of the source Vertex.
     * @param group A structure that holds the connected components
     * @return Does not return a value, but augments the group members.
     */
    void walkConnected(size_t pos, std::list<size_t> &group) {
        // If the Vertex was not visited
        if (!marks[pos]) {
            // Mark as visited and increments the group
            marks[pos] = true;
            group.push_back(pos);
            // Searchs for the children and then recursively for the children of the child
            for (auto edge : allVertex[pos].ownEdges)
                walkConnected(edge.get_dest(), group);
            // Searchs for the parents and then recursively for the parents of the parent
            for (auto par : allVertex[pos].parents)
                walkConnected(par, group);
        }
    }

    /**
     * Implementation of the Bron Kerbosch algorithm without pivoting. It is a recursive algorithm to find all the maximais cliques
     * of a nondirected graph.
     * @param R constains verticies that were already visited, candidates for the maximal clique.
     * @param P constains verticies to be visited.
     * @param X constains verticies that were already visited, but does not extends R..
     * @return Does not return a value, but augments the group members.
     */
    void recursiveBronKerbosch(std::set<int> R, std::set<int> P, std::set<int> X) const {
        // Stop condition
        if (P.empty() && X.empty()) {
            std::cout << "Clique found! It has " << R.size() << " verticies." << std::endl;
            printFromSet(R);
        }
        // Get an element from the P set using an iterator
        std::set<int>::iterator v = P.begin();
        while (!P.empty() && v != P.end()) {
            // Construct a set using the element
            std::set<int> v_of_P = { (*v) };
            // Calls the recursive function again, using subsets
            // Checks the neighbours of v
            recursiveBronKerbosch(sUnion(R, v_of_P),
                                  intersection(P, allVertex.at(*v).getNeighboursPos()),
                                  intersection(X, allVertex.at(*v).getNeighboursPos())
                                 );
            // Removes v from P and adds to X
            P = difference(P, v_of_P);
            X = sUnion(X, v_of_P);
            // Get the first element of P if P is not empty
            if (!P.empty()) {
                v = P.begin();
            }
        }
    }

    double ClusteringCoeff(Vertex<T> vert) const {
        // If the vetex has no neighbours or one neighbour its clustering is zero
        if (vert.size() <= 1) {
            return 0;
        }
        // Get a set of all the neighbours of the vertex
        std::set<int> neighbours = vert.getNeighboursPos();
        // Calculate the maximum number of triangles possible
        double max_triangles = vert.size() * (vert.size() - 1) / 2;
        double triangles = 0;
        Vertex<T> neighbour;
        // Calculate the effective number of triangles
        // Verify which neighbours are connected
        for (Edge edge : vert.ownEdges) {
            neighbour = allVertex.at(edge.get_dest());
            if (neighbour.has_neighbours()) {
                triangles += intersection(neighbours, neighbour.getNeighboursPos()).size();
            }
        }
        // Since some connections are computed twice, needs to be divided by two
        return (triangles / 2) / max_triangles;
    }

    std::vector< Vertex <T> > Kahn() const {
        std::map< int, int > verticiesIndegree;
        std::vector <Vertex <T> > topOrder;
        std::queue <Vertex <T> > zeroIndegree;
        int indegree;
        Vertex<T> neighbour;
        Vertex<T> vert;
        for (Vertex <T> vert : allVertex) {
            indegree = vert.indegree();
            verticiesIndegree.insert( std::pair< int, int>(vert.get_pos(), indegree));
            if (indegree == 0) {
                zeroIndegree.push(vert);
            }
        }
        while (!zeroIndegree.empty()) {
            vert = zeroIndegree.front();
            for (Edge edge : vert.ownEdges) {
                neighbour = allVertex.at(edge.get_dest());
                --verticiesIndegree.at(neighbour.get_pos());
                if (verticiesIndegree.at(neighbour.get_pos()) == 0) {
                    zeroIndegree.push(neighbour);
                }
            }
            topOrder.push_back(vert);
            zeroIndegree.pop();
        }
        return topOrder;
    }

    static bool pathComparator(Path lhs, Path rhs) {
        return lhs.cost < rhs.cost;
    }

};

#endif
