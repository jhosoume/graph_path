#ifndef EDGE
#define EDGE

/**
 * \class Edge
 * \brief Connection between two Vertex. This structure is stored in the source vertex and has the information of the cost and destination of the edge.
 * This structure allows traverse throught Vertex of a LinkedGraph.
 * \author: jhosoume
 * \date: 2018/08/26 20:00:00
 *
 * Contact: ju.hosoume@gmail.com
 */
class Edge {
public:
    /**
     * Edge constructor.
     * Defines default values for the basic attributes. Since the edges are going to be stored
     * in the source Vertex, the edges aren't going to contain this information.
     * @param dest define destination vertex.
     * @param weight represents the cost to travel throught this edge.
     * @return The Edge with its cost and destination defined.
     */
    Edge(size_t dest, float weight)
    : dest{dest}, weight{weight}
    {}

    Edge()
    : dest{0}, weight{0}
    {}
    /**
     * Edge destructor.
     * Releases not only the space of the current node, but also its ramifications.
     */
    // ~Edge()

    /**
     * Function to obtain position of the edges (Edge) destination.
     * Function to provide help in retriving the destination position of the given Edge.
     * @return A unsigned number that corresponds to the position of the given destination of the edge in the vector stored by the graph.
     */
    size_t get_dest() {
        return dest;
    }
    /**
     * Function to obtain the cost of the following the Edge.
     * Function to provide help in retriving the weight of the given Edge.
     * @return A floating point number that indicates the cost to traverse this Edge.
     */
    float get_weight() {
        return weight;
    }

    /**
     * Equality function to define when an edge is equal to another.
     * @param another_edge defines the edge to be compared with this object
     * @return Boolean to indicates if the equality is true or not.
     */
    bool operator==(const Edge& another_edge) const {
        return (dest == another_edge.dest) && (weight == another_edge.weight);
    }

private:
    size_t dest; ///< Information of the destination of the edge on the vector of vertex stored on the graph/
    float weight; ///< Cost of traversing the edge.
};

#endif
