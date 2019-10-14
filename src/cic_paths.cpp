#include "Graph.hpp"

int main(void) {
  // Creates a Digraph of mandatory UnB CiC Classes
  LinkedGraph<std::string> cic_curriculum = LinkedGraph<std::string>();

  // Adding Vertices
  cic_curriculum.insertVertex("Calculo1");
  cic_curriculum.insertVertex("ISC");
  cic_curriculum.insertVertex("APC");
  cic_curriculum.insertVertex("InfoSoc");
  cic_curriculum.insertVertex("FTC");
  cic_curriculum.insertVertex("CircuitosLogicos");
  cic_curriculum.insertVertex("LabdeCircuitosLogicos");
  cic_curriculum.insertVertex("Calculo2");
  cic_curriculum.insertVertex("IAL");
  cic_curriculum.insertVertex("ED");
  cic_curriculum.insertVertex("OAC");
  cic_curriculum.insertVertex("TP1");
  cic_curriculum.insertVertex("Algebra1");
  cic_curriculum.insertVertex("CN");
  cic_curriculum.insertVertex("PE");
  cic_curriculum.insertVertex("LC1");
  cic_curriculum.insertVertex("TP2");
  cic_curriculum.insertVertex("TAGrafos");
  cic_curriculum.insertVertex("Redes");
  cic_curriculum.insertVertex("LP");
  cic_curriculum.insertVertex("Concorrente");
  cic_curriculum.insertVertex("ES");
  cic_curriculum.insertVertex("BD");
  cic_curriculum.insertVertex("IIA");
  cic_curriculum.insertVertex("SB");
  cic_curriculum.insertVertex("SO");
  cic_curriculum.insertVertex("Automatos");
  cic_curriculum.insertVertex("SI");
  cic_curriculum.insertVertex("CE");
  cic_curriculum.insertVertex("PAA");
  cic_curriculum.insertVertex("Compiladores");
  cic_curriculum.insertVertex("Seguranca");
  cic_curriculum.insertVertex("MetCien");
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
  cic_curriculum.CriticalPath();

    return 0;
}
