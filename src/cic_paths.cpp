#include "Graph.hpp"

int main(void) {
  // Sets to true if want graph with the name of the classes
  std::cout << "Ciência da Computaçao" << std::endl;
  if (true) {
      // Creates a Digraph of mandatory UnB CiC Classes
      LinkedGraph<std::string> cic_curriculum = LinkedGraph<std::string>();

      // Adding Vertices
      cic_curriculum.insertVertex("Calculo1", 6);
      cic_curriculum.insertVertex("ISC", 4);
      cic_curriculum.insertVertex("APC", 6);
      cic_curriculum.insertVertex("InfoSoc", 2);
      cic_curriculum.insertVertex("FTC", 4);
      cic_curriculum.insertVertex("CircuitosLogicos", 4);
      cic_curriculum.insertVertex("LabdeCircuitosLogicos", 2);
      cic_curriculum.insertVertex("Calculo2", 6);
      cic_curriculum.insertVertex("IAL", 4);
      cic_curriculum.insertVertex("ED", 4);
      cic_curriculum.insertVertex("OAC", 4);
      cic_curriculum.insertVertex("TP1", 4);
      cic_curriculum.insertVertex("Algebra1", 4);
      cic_curriculum.insertVertex("CN", 4);
      cic_curriculum.insertVertex("PE", 4);
      cic_curriculum.insertVertex("LC1", 4);
      cic_curriculum.insertVertex("TP2", 4);
      cic_curriculum.insertVertex("TAGrafos", 4);
      cic_curriculum.insertVertex("Redes", 4);
      cic_curriculum.insertVertex("LP", 4);
      cic_curriculum.insertVertex("Concorrente", 4);
      cic_curriculum.insertVertex("ES", 4);
      cic_curriculum.insertVertex("BD", 4);
      cic_curriculum.insertVertex("IIA", 4);
      cic_curriculum.insertVertex("SB", 4);
      cic_curriculum.insertVertex("SO", 6);
      cic_curriculum.insertVertex("Automatos", 4);
      cic_curriculum.insertVertex("SI", 4);
      cic_curriculum.insertVertex("CE", 4);
      cic_curriculum.insertVertex("PAA", 4);
      cic_curriculum.insertVertex("Compiladores", 4);
      cic_curriculum.insertVertex("Seguranca", 4);
      cic_curriculum.insertVertex("MetCien", 4);
      std::cout << "The CIC Curriculum Graph has " << cic_curriculum.num_vertices() << " Vertices\n";

      // Adding Edges (Directed weightned)
      cic_curriculum.insertConnection("APC", "CircuitosLogicos", 6);
      cic_curriculum.insertConnection("APC", "LabdeCircuitosLogicos", 6);
      cic_curriculum.insertConnection("APC", "ED", 6);
      cic_curriculum.insertConnection("Calculo1", "Calculo2", 6);
      cic_curriculum.insertConnection("CircuitosLogicos", "OAC", 4);
      cic_curriculum.insertConnection("LabdeCircuitosLogicos", "OAC", 2);
      cic_curriculum.insertConnection("ED", "TP1", 4);
      cic_curriculum.insertConnection("Calculo2", "CN", 6);
      cic_curriculum.insertConnection("Calculo1", "PE", 6);
      cic_curriculum.insertConnection("FTC", "LC1", 4);
      cic_curriculum.insertConnection("TP1", "TP2", 4);
      cic_curriculum.insertConnection("ED", "TAGrafos", 4);
      cic_curriculum.insertConnection("ED", "Redes", 4);
      cic_curriculum.insertConnection("ED", "LP", 4);
      cic_curriculum.insertConnection("OAC", "Concorrente", 4);
      cic_curriculum.insertConnection("TP2", "Concorrente", 4);
      cic_curriculum.insertConnection("LP", "ES", 4);
      cic_curriculum.insertConnection("ED", "IIA", 4);
      cic_curriculum.insertConnection("OAC", "SB", 4);
      cic_curriculum.insertConnection("ED", "SB", 4);
      cic_curriculum.insertConnection("Concorrente", "SO", 4);
      cic_curriculum.insertConnection("Algebra1", "Automatos", 4);
      cic_curriculum.insertConnection("ED", "SI", 4);
      cic_curriculum.insertConnection("PE", "CE", 4);
      cic_curriculum.insertConnection("ED", "CE", 4);
      cic_curriculum.insertConnection("Calculo1", "PAA", 6);
      cic_curriculum.insertConnection("ED", "PAA", 4);
      cic_curriculum.insertConnection("LP", "Compiladores", 4);
      cic_curriculum.insertConnection("SB", "Compiladores", 4);
      cic_curriculum.insertConnection("Automatos", "Compiladores", 6);
      cic_curriculum.insertConnection("Redes", "Seguranca", 4);

      std::cout << "The CIC Curriculum Graph has " << cic_curriculum.num_edges() << " Edges\n";
      cic_curriculum.print();
      cic_curriculum.printTopologicalOrder("CIC_TopologicalOrder", "CIC_TopologicalOrder.dot");
      cic_curriculum.writeDigraphAsDot("CIC_Curriculum", "all_cic_curriculum.dot");
      cic_curriculum.CriticalPath(5);
  }


  // Sets to true if want graph with the classes codes
  if (true) {
      // Creates a Digraph of mandatory UnB CiC Classes
      LinkedGraph<std::string> cic_curriculum = LinkedGraph<std::string>();

      // Adding Vertices
      cic_curriculum.insertVertex("113034", 6);
      cic_curriculum.insertVertex("113468", 4);
      cic_curriculum.insertVertex("113476", 6);
      cic_curriculum.insertVertex("113476", 2);
      cic_curriculum.insertVertex("113450", 4);
      cic_curriculum.insertVertex("129011", 4);
      cic_curriculum.insertVertex("129020", 2);
      cic_curriculum.insertVertex("113042", 6);
      cic_curriculum.insertVertex("113093", 4);
      cic_curriculum.insertVertex("116319", 4);
      cic_curriculum.insertVertex("116394", 4);
      cic_curriculum.insertVertex("117889", 4);
      cic_curriculum.insertVertex("113107", 4);
      cic_curriculum.insertVertex("113417", 4);
      cic_curriculum.insertVertex("115045", 4);
      cic_curriculum.insertVertex("117366", 4);
      cic_curriculum.insertVertex("117897", 4);
      cic_curriculum.insertVertex("117901", 4);
      cic_curriculum.insertVertex("116572", 4);
      cic_curriculum.insertVertex("116343", 4);
      cic_curriculum.insertVertex("117935", 4);
      cic_curriculum.insertVertex("116441", 4);
      cic_curriculum.insertVertex("116378", 4);
      cic_curriculum.insertVertex("116653", 4);
      cic_curriculum.insertVertex("116432", 4);
      cic_curriculum.insertVertex("117960", 4);
      cic_curriculum.insertVertex("116882", 6);
      cic_curriculum.insertVertex("116416", 4);
      cic_curriculum.insertVertex("117943", 4);
      cic_curriculum.insertVertex("117536", 4);
      cic_curriculum.insertVertex("117951", 4);
      cic_curriculum.insertVertex("117927", 4);
      cic_curriculum.insertVertex("117919", 2);
      std::cout << "The CIC Curriculum Graph has " << cic_curriculum.num_vertices() << " Vertices\n";

      // Adding Edges (Directed weightned)
      cic_curriculum.insertConnection("113476", "129011", 6);
      cic_curriculum.insertConnection("113476", "129020", 6);
      cic_curriculum.insertConnection("113476", "116319", 6);
      cic_curriculum.insertConnection("113034", "113042", 6);
      cic_curriculum.insertConnection("129011", "116394", 4);
      cic_curriculum.insertConnection("129020", "116394", 2);
      cic_curriculum.insertConnection("116319", "117889", 4);
      cic_curriculum.insertConnection("113042", "113417", 6);
      cic_curriculum.insertConnection("113034", "115045", 6);
      cic_curriculum.insertConnection("113450", "117366", 4);
      cic_curriculum.insertConnection("117889", "117897", 4);
      cic_curriculum.insertConnection("116319", "117901", 4);
      cic_curriculum.insertConnection("116319", "116572", 4);
      cic_curriculum.insertConnection("116319", "116343", 4);
      cic_curriculum.insertConnection("116394", "117935", 4);
      cic_curriculum.insertConnection("117897", "117935", 4);
      cic_curriculum.insertConnection("116343", "116441", 4);
      cic_curriculum.insertConnection("116319", "116653", 4);
      cic_curriculum.insertConnection("116394", "116432", 4);
      cic_curriculum.insertConnection("116319", "116432", 4);
      cic_curriculum.insertConnection("117935", "117960", 4);
      cic_curriculum.insertConnection("113107", "116882", 4);
      cic_curriculum.insertConnection("116319", "116416", 4);
      cic_curriculum.insertConnection("115045", "117943", 4);
      cic_curriculum.insertConnection("116319", "117943", 4);
      cic_curriculum.insertConnection("113034", "117536", 6);
      cic_curriculum.insertConnection("116319", "117536", 4);
      cic_curriculum.insertConnection("116343", "117951", 4);
      cic_curriculum.insertConnection("116432", "117951", 4);
      cic_curriculum.insertConnection("116882", "117951", 6);
      cic_curriculum.insertConnection("116572", "117927", 4);

      std::cout << "The CIC Curriculum Graph has " << cic_curriculum.num_edges() << " Edges\n";
      cic_curriculum.print();
      cic_curriculum.printTopologicalOrder("CIC_TopologicalOrder_Codes", "CIC_TopologicalOrder_codes.dot");
      cic_curriculum.writeDigraphAsDot("CIC_Curriculum_Codes", "all_cic_curriculum_codes.dot");
      cic_curriculum.CriticalPath(5);
  }

    return 0;
}
