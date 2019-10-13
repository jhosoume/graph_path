#ifndef VERTEX
#define VERTEX

/*
 *  NOME: Juliana Mayumi Hosoume
 *  MATRICULA: 18/0048864
 *  MATÉRIA: Teoria e Aplicação de Grafos
 *  SEMESTRE: Segundo Semestre de 2019
 *  CURSO: Ciência da Computação
*/

#include <iostream>
#include <stdexcept>
#include <list>
#include <set>

#include "Edge.hpp"


/**
 * \class Vertex
 * \brief Basic structure for graph (LinkedGraph) construction
 * This class is the basic implementation for a graph Vertex. Actually it works just as the minimum repetitive
 * structure of a graph.
 * \author: jhosoume
 * \date: 2018/08/26 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
template <typename T> // Template for class and Graph Vertex. Needs to be outside since the compiler
                      // needs to know the size of the data to be provided.
                      // The following class has all the definitions of methods that should be on
                      // the .cpp, because the template requires the implementation followed by the
                      // definition.
class Vertex {
public:
    /**
     * Vertex constructor.
     * Defines default values for the basic attributes.
     * @param value an argument with the base type for the vertex. Defines the desired information.
     * @param pos represents the vector position on the graph (LinkedGraph) class.
     * @param edges a list off edges pointers
     * @return A Vertex with the value specified.
     */
    Vertex(T value, size_t pos, std::list< Edge > edges)
    : id{value}, position{pos}, ownEdges{edges}
    {}

    /**
     * Simpler Vertex constructor.
     * Defines default values for the basic attributes. In this case, the list of edges isn't necessary. The
     * Vertex is considered as having no Edge.
     * @param value an argument with the base type for the vertex. Defines the desired information.
     * @param pos represents the vector position on the graph class.
     * @return The Vertex with the value specified, Edge list field is empty.
     */
    Vertex(T value, size_t pos)
    : id{value}, position{pos}
    {}

    /**
     * Simpler Vertex constructor.
     * Defines default values for the basic attributes. In this case, the list of edges isn't necessary. The
     * Vertex is considered as having no Edge.
     * @param value an argument with the base type for the vertex. Defines the desired information.
     * @param pos represents the vector position on the graph class.
     * @return The Vertex with the value specified, Edge list field is empty.
     */
    Vertex() {}


    /**
     * Vertex destructor.
     * Releases not only the space of the current node, but also its ramifications.
     */
    // ~Vertex() {
    //     for (auto item : ownEdges) {
    //         delete item;
    //     }
    // }

    /**
     * Auxiliary function to obtain the identification of the vertex.
     * Function to provide help in retriving the identification of the given vertex.
     * @return The identification of type defined by the template of the graph.
     */
    T get_id() const {
        return id;
    }

    /**
     * Auxiliary function to obtain the position of the vertex.
     * Function to provide help in retriving the position of the given vertex in the vector of vertex stored in the graph.
     * @return An unsigned integer that represents the position on the vector of vertex stored in the graph.
     */
    size_t get_pos() const {
        return position;
    }

    /**
     * Auxiliary function to obtain the number of edges that leaves the vertex.
     * Function to provide help in retriving the total number of edges that goes out the vertex.
     * @return An unsigned integer that represents the total number of edges from this vertex.
     */
    size_t size() const {
        // Uses the list auxiliary function
        return ownEdges.size();
    }

    /**
     * Auxiliary function to obtain if the vertex has any neighbour.
     * Function to provide help in retriving the information about the existence of neighbours of the vertex.
     * @return A boolen indicating the existence of neighbours. Returns true if there are neighbours and false otherwise.
     */
    bool has_neighbours() const {
        // Only checking the list of edges size
        if (ownEdges.size() != 0)
            return true;
        return false;
    }

    /**
     * Auxiliary function to obtain if the vertex has any parent.
     * Function to provide help in retriving the information about the existence of parents of the vertex.
     * @return A boolen indicating the existence of parents. Returns true if there are parents and false otherwise.
     */
    bool has_parents() const {
        // Checking the list size
        if (parents.size() != 0)
            return true;
        return false;
    }

    /**
     * Equality function to define when a vertex is equal to another.
     * @param another_vertex defines the vertex to be compared with this object
     * @return Boolean to indicates if the equality is true or not.
     */
    bool operator==(const Vertex& another_vertex) const {
        return (std::equal(ownEdges.begin(),
                           ownEdges.end(),
                           another_vertex.ownEdges.begin())) &&
               (id == another_vertex.id) &&
               (position == another_vertex.position);
    }

    bool operator!=(const Vertex& another_vertex) const {
        return !operator==(another_vertex);
    }

    /**
     * Auxiliary function to obtain who are the parents of the vertex.
     * Function to print all the parents of this vertex.
     */
    void print_parents() const {
        // Case to check if there are truly any vertex.
        if (!has_parents()) {
            std::cout << "This Vertex " << position <<  " is orphan! It has no parents!" << std::endl;
            return;
        }
        // Loop to visit every parent and print its position on the vector of vertex.
        std::cout << " It has a total of " << parents.size() << std::endl;
        // Loop throught values stored in the list
        for (auto parent : parents) {
            std::cout << "Parent " << parent << std::endl;
        }
    }

    /**
     * Auxiliary function to obtain the number of edges that leaves the vertex.
     * Function to provide help in retriving the total number of edges that goes out the vertex.
     * @return An integer that represents the total number of edges from this vertex.
     */
    int degree() const {
      return ownEdges.size();
    }

    int indegree() const {
        return parents.size();
    }

    /**
     * Auxiliary function to obtain the position of the neighbours in the graph stored in a set.
     * @return A set of positions defined as integers.
     */
    std::set<int> getNeighboursPos() const {
        std::set<int> neighbours;
        for (Edge edge : ownEdges) {
            neighbours.insert(edge.get_dest());
        }
        return neighbours;
    }


    std::list< Edge > ownEdges; ///< List of pointers of edges (Edges) that originates of the given vertex.
    std::list< size_t > parents; ///< All vexters that has edges that have this vertex as destination.

private:
    T id; ///< Identification of the Vertex, may store names or other information.
    size_t position; ///< Represents the position in the graph. It is sequential according to the order of insertion on the graph
};

#endif
