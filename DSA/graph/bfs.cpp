#include <iostream>
using namespace std;

class UndirectedGraph {
private:
    static const int MAX_NODES = 100; // max limit for safety
    int N;                            // actual number of nodes
    int adj[MAX_NODES][MAX_NODES];   // adjacency list using arrays
    int deg[MAX_NODES];              // degree tracker

public:
    UndirectedGraph(int n) {
        N = n;
        for (int i = 0; i < N; i++) {
            deg[i] = 0;
        }
    }

    // Add an undirected edge
    void addEdge(int u, int v) {
        if (u < 0 || u >= N || v < 0 || v >= N) {
            cout << "❌ Invalid edge (" << u << ", " << v << ")\n";
            return;
        }
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // Print the graph
    void printGraph() {
        cout << "\n🔗 Undirected Graph Structure:\n";
        for (int i = 0; i < N; i++) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < deg[i]; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};



class DirectedGraph {
private:
    static const int MAX_NODES = 100;
    int N;
    int adj[MAX_NODES][MAX_NODES];
    int deg[MAX_NODES];

public:
    DirectedGraph(int n) {
        N = n;
        for (int i = 0; i < N; i++) {
            deg[i] = 0;
        }
    }

    void addEdge(int u, int v) {
        if (u < 0 || u >= N || v < 0 || v >= N) {
            cout << "❌ Invalid edge (" << u << " → " << v << ")\n";
            return;
        }
        adj[u][deg[u]++] = v; // only one direction
    }

    void printGraph() {
        cout << "\n➡️ Directed Graph Structure:\n";
        for (int i = 0; i < N; i++) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < deg[i]; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};



int main() {


  return 0;
}
