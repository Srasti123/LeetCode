#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    long long count(int n) {
        // Calculate the number of edges in an undirected graph
        int numEdges = (n * (n - 1)) / 2;
        // Return the total number of possible graphs
        return pow(2, numEdges);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Total number of possible graphs: " << solution.count(n) << endl;
    return 0;
}
