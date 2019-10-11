#ifndef GRAPH
#define GRAPH

#include <algorithm>
#include <set>
#include <vector>

#include <Vertex.hpp>
#include <Edge.hpp>
#include <LinkedGraph.hpp>

/**
 * Reads a text file that contains information of a direct Graph of chars.
 * The first row of the file must contain the number of vertices followed by the
 * number of edges. The following rows must contain information of the
 * abstract position of the vertex and the data of each vertex.
 * After, the edges are defined by the source and destination vertex abstract
 * positions accompanied by the weight.
 * @param file defines the name of the file to be read.
 * @return a directed graph data structure that contains information in char type.
 */
LinkedGraph<char> readGraphofChars(std::string file);

/**
 * Reads a text file that contains information of a nondirect Graph of chars.
 * The first row of the file must contain the number of vertices followed by the
 * number of edges. The following rows must contain information of the
 * abstract position of the vertex and the data of each vertex.
 * After, the edges are defined by the source and destination vertex abstract
 * positions accompanied by the weight.
 * @param file defines the name of the file to be read.
 * @return a nondirected graph data structure that contains information in char type.
 */
LinkedGraph<char> readNonDirectedGraphofChars(std::string file, bool print = false);

/**
 * Reads specificaly a text file that contains information of a dolphins relationship
 * nondirect Graph.

 * @return a nondirected graph data structure that contains information of dolphins.
 */
LinkedGraph<int> readDolphins(bool print = false);


void allVerticesDegree(LinkedGraph<int>);

#endif
