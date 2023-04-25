#ifndef CTABLE_H
#define CTABLE_H

#include <iostream>
#include <fstream>
#include <random>

#include <vector>
#include <random>
#include <string>

#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
class CTable {
private:
    int m_rows;
    int m_cols;
    double** m_data;

public:
    // Constructor to randomly fill table
    CTable(int rows, int cols);

    // Constructor to read table from file
    CTable(std::string filename);

    // Destructor to free memory
    ~CTable();

    // Print function to display table
    void Print();

    // Save function to save table to file
    void Save(std::string filename);

    // Sort function to sort table in decreasing order
    void Sort();

    // Average function to return average value of data stored in table
    double Average();
};

//test
// Estructura del grafo
struct Graph {
    int V;  // número de nodos
    std::vector<std::vector<int>> adj;  // matriz de adyacencia

    // Constructor
    Graph(int V);

    // Añadir una arista entre u y v
    void addEdge(int u, int v);

    // Verificar si el grafo es conexo
    bool isConnected();

    // Recorrido DFS
    void dfs(int u, std::vector<bool>& visited);

    // Imprimir la lista de nodos con sus adyacentes
    void printAdjList();

    // Imprimir la matriz de adyacencia
    void printAdjMatrix();

    void SaveM(std::string filename);

    void generar_instancia(int v, int x[], int y[]);
};
//coor
const int MAX_N = 100;  // Máximo número de ciudades
const int MAX_COORD = 1000;  // Máxima coordenada

double dist(int x1, int y1, int x2, int y2);
void escribir_instancia(int n, int x[], int y[]);
#endif
