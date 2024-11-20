#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph1 {
private:
    vector<vector<int>> adjList;
    int vertices;

public:
    // Constructor
    UndirectedGraph1(int vertices) {
        this->vertices = vertices;
        adjList.resize(vertices); // Initialize the adjacency list
    }

    // Method to add an edge
    void addEdge(int vertex1, int vertex2) {
        if (vertex1 >= 0 && vertex1 < vertices && vertex2 >= 0 && vertex2 < vertices) {
            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }
    }

    // Method to display the graph
    void displayUndirectedGraph1() {
        cout << "Undirected Graph:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 4 vertices
    UndirectedGraph1 graph(4);

    // Add edges
    graph.addEdge(1, 0);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);

    // Display the graph
    graph.displayUndirectedGraph1();

    return 0;
}

