#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> createAdjList(int V, vector<vector<int>>& edges) {
        // Create an empty adjacency list
        vector<vector<int>> adjList(V);

        // Populate the adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v); // Add v to u's adjacency list
            adjList[v].push_back(u); // Add u to v's adjacency list (undirected graph)
        }

        return adjList;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution solution;
    vector<vector<int>> adjList = solution.createAdjList(V, edges);

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
