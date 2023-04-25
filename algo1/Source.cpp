#include <iostream>
#include <fstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "CTABLE.h"

using namespace std;



int main() {
    cout << "Que demonios quieres hacer \n";
    cout<< "1.Tablas\n";
    cout<< "2.Grafo\n";
    int OP = 0;
    cin >> OP;
    if (OP == 1) {
        int rows = 0;
        int cols = 0;
        std::string filename;
        cout << "filas:\n";
        cin >> rows;
        cout << "columnas:\n";
        cin >> cols;
        cout << "archivo: \n";
        cin >> filename;

        CTable table(rows, cols);
        table.Print();
        table.Sort();
        cout << "\n";
        table.Print();
        table.Save(filename);// print table data
        return 0;
    }
    if (OP == 2) {
        int V;
        std::string filename;
        cout << "Ingrese el número de nodos del grafo: ";
        cin >> V;
        cout << "archivo: \n";
        cin >> filename;
        // Crear el grafo
        Graph graph(V);

        // Generar las aristas al azar
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, V - 1);
        for (int i = 0; i < V * 2; i++) {
            int u = dis(gen);
            int v = dis(gen);
            graph.addEdge(u, v);
        }

        // Verificar si el grafo es conexo
        if (graph.isConnected()) {
            cout << "El grafo es conexo" << endl;
        }
        else {
            cout << "El grafo es disconexo" << endl;
        }

        // Imprimir la lista de nodos con sus adyacentes
        cout << endl;
        graph.printAdjList();

        // Imprimir la matriz de adyacencia
        cout << endl;
        graph.printAdjMatrix();
 //       graph.generar_instancia(int V, int x[], int y[]);
        graph.SaveM(filename);

        return 0;
    }
}
