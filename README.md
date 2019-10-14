# graph_clique

Matéria: Teoria e Aplicação de Grafos 117901
Segundo Semestre de 2019

Juliana Mayumi Hosoume 180048864

Compilado com g++ versão:
gcc version 5.5.0 20171010 (Ubuntu 5.5.0-12ubuntu1~16.04)

Para compilar o código, na pasta principal (root) do projeto:
$ make

Pode ser necessário realizar uma compilação limpa (eliminando os antigos binários), para isso fazer um
'clean':
$ make clean
$ make

Para executar o programa:
$ ./bin/cic_paths

Diretórios:
bin : arquivo executável do tradutor
build : arquivos objeto
include : headers dos arquivos C++
src : código em C++ do tradutor
tests : alguns testes utilizados
Makefile : arquivo que auxilia na compilação


Para compilar sem utilizar o Makefile, realizar (considerando que
    os diretórios build e bin foram eliminados):
$ mkdir build
$ mkdir bin
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/helper.o src/helper.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/cic_paths.o src/cic_paths.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/Graph.o src/Graph.cpp
$ g++ build/helper.o build/cic_paths.o build/Graph.o -o bin/cic_paths -lm

---

O arquivo principal é o cic_paths.cpp  -> nesse arquivo está a montagem do grafo, com as matérias como vértices e os pré-requisitos como arestas, assim como chama as principais funções para cálculo da ordem topológica e a busca pelos dois caminhos críticos.

A partir da execução do programa são gerados arquivos .dot para visualização pelo graphviz (http://www.graphviz.org/). São gerados dois arquivos, um com as matérias sendo reconhecidas pelos códigos (all_cic_curriculum_codes.dot) e outra pelos nomes (all_cic_curriculum.dot). Para gerar os arquivos com as imagens, é necessária a instalação do graphviz. No ubuntu, pode ser realizado com o seguinte comando no terminal:
$ sudo apt-get install graphviz
Em seguida, realiza os comandos:
$ dot -Tpng all_cic_curriculum_codes.dot -o all_cic_curriculum_codes.png
$  dot -Tpng all_cic_curriculum_codes.dot -o all_cic_curriculum_codes.png
Para visualização dos arquivos (os arquivos .png serão enviados junto com o programa para evitar a necessiadade de instalar o graphviz):
$ display all_cic_curriculum.png
$ display all_cic_curriculum_codes.png

A ordenação topológica, além de ser uma saída em tela do programa, também pode ser vista em versão extendida, por meio de:
$ dot -Tpng CIC_TopologicalOrder.dot -o CIC_TopologicalOrder.png
$ display CIC_TopologicalOrder.png

Além da sequência mais longa, são apresentadas a segunda sequência mais longa de duas formas: a segunda sequência mais longa com vértices (matérias) presentes na sequência mais longa e a sequência mais longa em que todos os vértices não estão presentes na primeira. O valor total e o valor das arestas no caminho são apresentados na tela, assim como os vértices em sequência topolǵica desses caminhos.
A sequência mais longo é mostrado em azul (first_critical_path.png):
$ dot -Tpng first_critical_path.dot  -o first_critical_path.png
$ display first_critical_path.png
A segunda sequência sem vértices repetidos é apresentada em verde.
$ dot -Tpng second_critical_path.dot  -o second_critical_path.png
$ display second_critical_path.png
