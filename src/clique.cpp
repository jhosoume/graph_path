#include <Graph.hpp>

int main(void) {
  // Checking if the Vertex and Edges are correctly being created
  // Vertex<int> Vert = Vertex<int>(0, 0);
  // Vertex<int> Vert2 = Vertex<int>(1, 0);
  // Edge Edg = Edge(0, 2.1);
  // Edge Edg2 = Edge(0, 2.21);
  // if (Vert == Vert2) {
  //     std::cout << "It worked!" << std::endl;
  //
  // } else {
  //     std::cout << "Something went wrong!" << std::endl;
  // }
  //
  //
  // // Creates a simple Graph using Code
  // LinkedGraph<std::string> GF = LinkedGraph<std::string>();
  // GF.insertVertex("Toronto");
  // GF.insertVertex("Chicago");
  // GF.insertVertex("Vancouver");
  // std::cout << "The Graph has " << GF.num_vertices() << " Vertices\n";
  // // GF.insertConnection("Toronto", "Chicago", 2.3);
  // // GF.insertConnection("Vancouver", "Chicago", 5.3);
  // GF.insertNondirectedConnection("Toronto", "Chicago", 2.3);
  // GF.insertNondirectedConnection("Vancouver", "Chicago", 5.3);
  // // GF.insertEdge(0, 2, 5);
  // // GF.insertEdge(1, 1, 5);
  // std::cout << "The Graph has " << GF.num_edges() << " Edges\n";
  // GF.print();
  // GF.BronKerbosch();

  // Test example from slide (UnB - Prof. Dibio)
  if (false) {
      std::string people[15] = { "Amy", "Jack", "Erin", "Sally", "Sue", "Max", "Jake", "Tom", "Lu", "Joe", "Ryan", "Jess", "Liz", "Ty", "Jay"};
      LinkedGraph<std::string> test = LinkedGraph<std::string>();
      for (std::string person : people) {
          test.insertVertex(person);
      }
      test.insertNondirectedConnection("Amy", "Erin", 1);
      test.insertNondirectedConnection("Amy", "Jack", 1);
      test.insertNondirectedConnection("Erin", "Jack", 1);
      test.insertNondirectedConnection("Erin", "Sally", 1);
      test.insertNondirectedConnection("Sally", "Sue", 1);
      test.insertNondirectedConnection("Sally", "Max", 1);
      test.insertNondirectedConnection("Max", "Sue", 1);
      test.insertNondirectedConnection("Sally", "Tom", 1);
      test.insertNondirectedConnection("Sally", "Jake", 1);
      test.insertNondirectedConnection("Tom", "Jake", 1);
      test.insertNondirectedConnection("Tom", "Jess", 1);
      test.insertNondirectedConnection("Tom", "Lu", 1);
      test.insertNondirectedConnection("Tom", "Ryan", 1);
      test.insertNondirectedConnection("Jess", "Jake", 1);
      test.insertNondirectedConnection("Jess", "Lu", 1);
      test.insertNondirectedConnection("Jess", "Ryan", 1);
      test.insertNondirectedConnection("Lu", "Ryan", 1);
      test.insertNondirectedConnection("Lu", "Jake", 1);
      test.insertNondirectedConnection("Lu", "Joe", 1);
      test.insertNondirectedConnection("Ryan", "Jake", 1);
      test.insertNondirectedConnection("Liz", "Jay", 1);
      test.insertNondirectedConnection("Liz", "Ty", 1);
      test.insertNondirectedConnection("Ty", "Jay", 1);
      test.print();
      test.BronKerbosch();
      test.printVerticiesClusteringCoeff();
  }

  // Test example from slide (UnB - Prof. Dibio)
  if (false) {
      LinkedGraph<int> slide_graph = LinkedGraph<int>();
      for (int value = 1; value <= 6; ++value) {
          slide_graph.insertVertex(value);
      }
      slide_graph.insertNondirectedConnection(1, 3, 1);
      slide_graph.insertNondirectedConnection(1, 4, 1);
      slide_graph.insertNondirectedConnection(1, 2, 1);
      slide_graph.insertNondirectedConnection(2, 4, 1);
      slide_graph.insertNondirectedConnection(2, 5, 1);
      slide_graph.insertNondirectedConnection(3, 4, 1);
      slide_graph.insertNondirectedConnection(4, 5, 1);
      slide_graph.insertNondirectedConnection(4, 6, 1);
      slide_graph.print();
      slide_graph.BronKerbosch();
      slide_graph.printVerticiesClusteringCoeff();
  }

  // Test example from slide (UnB - Prof. Dibio)
  if (false) {
      std::cout << "\n\n--------------------Test Clustering Coefficinet--------------------\n";
      std::string input = "tests/testCoefficient.dat";
      LinkedGraph<char> GF5 = readNonDirectedGraphofChars(input);
      GF5.print();
      GF5.BronKerbosch();
      GF5.printVerticiesClusteringCoeff();
      std::cout << "Mean Clustering Coefficient" << std::endl;
      std::cout << GF5.MeanClusteringCoeff() << std::endl;
  }

  // Testing a giant graphs
  if (false) {
      LinkedGraph<int> giant_graph = LinkedGraph<int>();
      for (int indx = 0; indx < 100; ++indx) {
          giant_graph.insertVertex(indx);
      }
      for (int indx = 0; indx < 100; ++indx) {
          for (int num = 0; num < 5; ++num) {
              int indx2 = (indx + num + 1) % 100;
              giant_graph.insertConnection(indx, indx2, 1);
          }
      }
      std::cout << "The Giant Graph has " << giant_graph.num_vertices() << " Vertices\n";
      std::cout << "The Giant Graph has " << giant_graph.num_edges() << " Edges\n";
      giant_graph.print();
  }

  // Dealing with the dolphins graph
  LinkedGraph<int> dolphins_graph = readDolphins();
  dolphins_graph.print();
  allVerticesDegree(dolphins_graph);
  dolphins_graph.BronKerbosch();
  dolphins_graph.printVerticiesClusteringCoeff();
  std::cout << "Mean Clustering Coefficient" << std::endl;
  std::cout << dolphins_graph.MeanClusteringCoeff() << std::endl;

  return 0;
}
