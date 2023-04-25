#include "CTable.h"

// Constructor to randomly fill table
CTable::CTable(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    m_data = new double* [rows];
    for (int i = 0; i < rows; i++) {
        m_data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            m_data[i][j] = rand() % 100; // fill with random values between 0 and 99
        }
    }
}

// Constructor to read table from file
CTable::CTable(std::string filename) {
    std::ifstream infile(filename);
    infile >> m_rows >> m_cols;
    m_data = new double* [m_rows];
    for (int i = 0; i < m_rows; i++) {
        m_data[i] = new double[m_cols];
        for (int j = 0; j < m_cols; j++) {
            infile >> m_data[i][j];
        }
    }
    infile.close();
}

// Destructor to free memory
CTable::~CTable() {
    for (int i = 0; i < m_rows; i++) {
        delete[] m_data[i];
    }
    delete[] m_data;
}

// Print function to display table
void CTable::Print() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            std::cout << m_data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Save function to save table to file
void CTable::Save(std::string filename) {
    std::ofstream outfile(filename);
    outfile << m_rows << " " << m_cols << std::endl;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            outfile << m_data[i][j] << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
}

// Sort function to sort table in decreasing order
void CTable::Sort() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            for (int k = 0; k < m_cols - j - 1; k++) {
                if (m_data[i][k] < m_data[i][k + 1]) {
                    double temp = m_data[i][k];
                    m_data[i][k] = m_data[i][k + 1];
                    m_data[i][k + 1] = temp;
                }
            }
        }
    }
}

// Average function to return average value of data stored in table
double CTable::Average() {
    double sum = 0;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            sum += m_data[i][j];
        }
    }
    return sum / (m_rows * m_cols);
}

using namespace std;

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, vector<int>(V, 0));
}

// Añadir una arista entre u y v
void Graph::addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Verificar si el grafo es conexo
bool Graph::isConnected() {
    vector<bool> visited(V, false);
    dfs(0, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

// Recorrido DFS
void Graph::dfs(int u, vector<bool>& visited) {
    visited[u] = true;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, visited);
        }
    }
}

// Imprimir la lista de nodos con sus adyacentes
void Graph::printAdjList() {
    for (int i = 0; i < V; i++) {
        cout << "Nodo " << i << ": ";

        bool first = true;
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                if (!first) {
                    cout << ", ";
                }
                cout << j;
                first = false;
            }
        }

        cout << endl;
    }
}

// Imprimir la matriz de adyacencia
void Graph::printAdjMatrix() {
    cout << "Matriz de adyacencia:" << endl;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Guardar en un archivo
void Graph::SaveM(std::string filename) {
    cout << "Matriz de adyacencia:" << endl;
    std::ofstream outfile(filename);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            outfile << adj[i][j] << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
}
//cooordenadas
double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Graph::generar_instancia(int V, int x[], int y[]) {
    srand(time(0));  // Inicializar semilla para generación aleatoria

    // Generar coordenadas aleatorias para cada ciudad
    for (int i = 0; i < V; i++) {
        x[i] = rand() % MAX_COORD + 1;
        y[i] = rand() % MAX_COORD + 1;
    }
}

void escribir_instancia(int n, int x[], int y[]) {
    // Escribir instancia en archivo
    ofstream fout("tsp_instance.txt");
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << x[i] << " " << y[i] << endl;
    }
    fout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                fout << i << " " << j << " " << dist(x[i], y[i], x[j], y[j]) << endl;
            }
        }
    }
    fout.close();
}