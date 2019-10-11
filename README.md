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
$ ./bin/clique

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
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/clique.o src/clique.cpp
$ g++ -std=c++11 --pedantic -O3 -I include -c -o build/Graph.o src/Graph.cpp
$ g++ build/helper.o build/clique.o build/Graph.o -o bin/clique -lm

---

O arquivo principal é o clique.cpp  -> nesse arquivo está a leitura do arquivo soc-dolphins.mtx
Quando executado o programa imprime na tela os vértices e seus graus, os cliques maximais, além do coeficiente de aglorameração de cada vértice e o coeficiente médio do grafo.
