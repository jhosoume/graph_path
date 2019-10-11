#include "Graph.hpp"


/**
 * Auxiliary function that reads all the information of the structure of a directed LinkedGraph with
 * identification of the Vertex represented by a char.
 * The first line must contain the Number of Vertices and the the Number of Edges.
 * The following lines contains the vertex position (size_t) and its identification (char).
 * The othe lines are the edges, consisting of the source position (size_t), destination position (size_t) and then the cost (float).
 * @param file A string containing all the name relative to the file that contains the structure of the graph.
 * @return A LinkedGraph of chars containg all the information that is in the file.
 */
LinkedGraph<char> readGraphofChars(std::string file) {
    // Dealing with the file
    std::ifstream infile;
    infile.open(file, std::ios::in);
    if (!infile)
       std::cerr << "Could not open file" << file << "\n";
    // Reading the information about the total number of vertices and edges
    size_t n_edg, n_vert;
    infile >> n_vert >> n_edg;
    // Creates the LinkedGraph datastructure to hold the information
    LinkedGraph<char> graph = LinkedGraph<char>();
    size_t pos;
    char id;
    // Loop to read the vertices
    for (size_t i = 0; i < n_vert; i++) {
        infile >> pos >> id;
        std::cout << "Vertex-> Position " << pos << " id " << id << "\n";
        graph.insertVertex(id);
    }
    size_t src_pos, dest_pos;
    float weight;
    // Loop to read the edges
    for (size_t j = 0; j < n_edg; j++) {
        infile >> src_pos >> dest_pos >> weight;
        std::cout << "Edge-> Position " << src_pos << " to pos " << dest_pos <<" weight " << weight << "\n";
        graph.insertEdge(src_pos, dest_pos, weight);
    }
    return graph;
}

/**
 * Auxiliary function presented ithat reads all the information of the structure of a non directed LinkedGraph with
 * identification of the Vertex represented by a char.
 * The first line must contain the Number of Vertices and the the Number of Edges.
 * The following lines contains the vertex position (size_t) and its identification (char).
 * The othe lines are the edges, consisting of the source position (size_t), destination position (size_t) and then the cost (float).
 * @param file A string containing all the name relative to the file that contains the structure of the graph.
 * @return A LinkedGraph of chars containg all the information that is in the file.
 */
LinkedGraph<char> readNonDirectedGraphofChars(std::string file, bool print) {
    // Dealing with the file
    std::ifstream infile;
    infile.open(file, std::ios::in);
    if (!infile)
       std::cerr << "Could not open file" << file << "\n";
    // Reading the information about the total number of vertices and edges
    size_t n_edg, n_vert;
    infile >> n_vert >> n_edg;
    // Creates the LinkedGraph datastructure to hold the information
    LinkedGraph<char> graph = LinkedGraph<char>();
    size_t pos;
    char id;
    // Loop to read the vertices
    for (size_t i = 0; i < n_vert; i++) {
        infile >> pos >> id;
        if (print) {
            std::cout << "Vertex-> Position " << pos << " id " << id << "\n";
        }
        graph.insertVertex(id);
    }
    size_t src_pos, dest_pos;
    float weight;
    // Loop to read the edges
    for (size_t j = 0; j < n_edg; j++) {
        infile >> src_pos >> dest_pos >> weight;
        if (print) {
            std::cout << "Edge-> Position " << src_pos << " to pos " << dest_pos <<" weight " << weight << "\n";
        }
        graph.insertNondirectedEdge(src_pos, dest_pos, weight);
    }
    return graph;
}

/**
 * Auxiliary function that reads all the information of the structure of a directed LinkedGraph with
 * identification of the Vertex represented by a integer.
 * The first line must contain the Number of Vertices and the the Number of Edges.
 * The following lines contains the vertex position (size_t) and its identification (ints).
 * The othe lines are the edges, consisting of the source position (size_t), destination position (size_t) and then the cost (float).
 * @param file A string containing all the name relative to the file that contains the structure of the graph.
 * @return A LinkedGraph of ints containg all the information that is in the file.
 */
LinkedGraph<int> readGraphofInts(std::string file) {
    // Same description as the readGraphofChars()
    std::ifstream infile;
    infile.open(file, std::ios::in);
    if (!infile)
       std::cerr << "Could not open file" << file << "\n";
    size_t n_edg, n_vert;
    infile >> n_vert >> n_edg;
    LinkedGraph<int> graph = LinkedGraph<int>();
    size_t pos;
    int id;
    for (size_t i = 0; i < n_vert; i++) {
        infile >> pos >> id;
        std::cout << "Vertex-> Position " << pos << " id " << id << "\n";
        graph.insertVertex(id);
    }
    size_t src_pos, dest_pos;
    float weight;
    for (size_t j = 0; j < n_edg; j++) {
        infile >> src_pos >> dest_pos >> weight;
        std::cout << "Edge-> Position " << src_pos << " to pos " << dest_pos <<" weight " << weight << "\n";
        graph.insertEdge(src_pos, dest_pos, weight);
    }
    return graph;
}

/**
 * Auxiliary function that creates a Graph of Integers composed of random vertices (Vertex) and edges (Edge). The LinkedGraph will be constitued by a number of vertices and edges specified. Identification of the Vertex represented by an integer. Writes the random graph in a file named random_graph.out.
 * The first line contains the Number of Vertices and the the Number of Edges.
 * The following lines contains the vertex position (size_t) and its identification (int).
 * The othe lines are the edges, consisting of the source position (size_t), destination position (size_t) and then the cost (float).
 * @param nVert Number of vertices (Vertex) that the LinkedGraph will be composed of.
 * @param nEdge Total number of edges (Edges) that the LinkedGraph will be composed of.
 * @param file A string containing all the name relative to the file that will contain the structure of the graph.
 * @param out Specifies if the file will be written or not
 * @return A LinkedGraph of ints containg randomly generated.
 */
LinkedGraph<int> randomGraphofInts(size_t nVert, size_t nEdge, std::string file = "random_graph.out", bool out = true) {
    // Opening output file
    std::ofstream outfile;
    outfile.open(file, std::ios::out);
    if (!outfile)
       std::cerr << "Could not open file" << file << "\n";
    outfile << nVert << " " <<  nEdge << std::endl;
    // Creating Graph and insert vertices sequentialy
    LinkedGraph<int> graph = LinkedGraph<int>();
    for (size_t i = 0; i < nVert; i++) {
        outfile << i << " " << i+1 << std::endl;
        //std::cout << "Vertex-> Position " << i << " id " << i+1 << "\n";
        graph.insertVertex(i);
    }
    size_t j = 0;
    // Including edges with random source and destination
    while (j < nEdge) {
        size_t src_pos = static_cast <size_t> (std::rand() % nVert);
        size_t dest_pos = static_cast <size_t> (std::rand() % nVert);
        while (dest_pos == src_pos) {
            dest_pos = static_cast <size_t> (std::rand() % nVert);
        }
        // Randomly generating the cost of the edge
        float weight = static_cast <float> (std::rand() % 100) / static_cast <float>(10);
        if (graph.has_edge(src_pos, dest_pos)) {
            continue;
        }
        outfile << src_pos << " "<< dest_pos << " " << weight << std::endl;
        //std::cout << "Edge-> Position " << src_pos << " to pos " << dest_pos <<" weight " << we
//ight << "\n";
        graph.insertEdge(src_pos, dest_pos, weight);
        j++;
    }
    return graph;
}

/**
 * Auxiliary function that creates a Graph of Integers based on the work  of
 * “David   Lusseau   et   al.,  The   bottelenose   dolphin   community   of   Doubful   Soundfeatures   a
 *  large   proportion   of   long-lasting   associations,   Journal of Behavioral Ecology andSociobiology54:4, 396--405 (2003).”
 * @param print Specifies screen output will be produced to help debug
 * @return A LinkedGraph of ints contaning information of a social network of dolphins
 */
LinkedGraph<int> readDolphins(bool print) {
    std::ifstream infile;
    infile.open("specs/soc-dolphins.mtx", std::ios::in);
    // Check if the file was correctly opened
    if (!infile.is_open())
       std::cerr << "Could not open dolphins file." << std::endl;
    std::string line;
    // while((std::getline(infile, line)) && (line.at(0) == '%'));
    // Skip comments lines
    for (int indx = 1; indx <= 35; ++indx) {
        std::getline(infile, line);
    }
    int num_vertex, num_edges;
    infile >> num_vertex >> num_vertex >> num_edges;
    LinkedGraph<int> graph = LinkedGraph<int>();
    size_t pos;
    int id;
    // Creates verticies
    for (size_t num = 0; num < num_vertex; ++num) {
        pos = num;
        id = num + 1;
        if (print) {
            std::cout << "Vertex-> Position " << pos << " id " << id << "\n";
        }
        graph.insertVertex(id);
    }
    size_t src_pos, dest_pos;
    float weight = 1;
    // Creates edges with the same weight so that the weight can be ignored
    for (int indx = 0; indx < num_edges; ++indx) {
        infile >> src_pos >> dest_pos;
        if (print) {
            std::cout << "Edge-> Position " << src_pos << " to pos " << dest_pos <<" weight " << weight << "\n";
        }
        graph.insertNondirectedConnection(src_pos, dest_pos, weight);
    }

    return graph;
}

// Function to output all verticies degrees of a graph
void allVerticesDegree(LinkedGraph<int> graph) {
std::cout << "Vertex Data" << " | " << "Vertex Pos" << " | " << "Degree" << std::endl;
  for (Vertex<int> vert : graph.getVertices()) {
    std::cout << vert.get_id() << " | " << vert.get_pos() << " | " << vert.degree() << std::endl;
  }
}
