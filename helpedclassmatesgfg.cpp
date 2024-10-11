#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findHelperMarks(vector<int>& marks) {
    int n = marks.size();
    vector<int> result(n, -1);  
    stack<int> s;  
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && marks[s.top()] >= marks[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = marks[s.top()];
        }
        s.push(i);
    }
    
    return result;
}

int main() {
    // Example 1
    vector<int> marks1 = {3, 8, 5, 2, 25};
    vector<int> result1 = findHelperMarks(marks1);
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;  // Output: 2 5 2 -1 -1
    
    // Example 2
    vector<int> marks2 = {1, 2, 3, 4};
    vector<int> result2 = findHelperMarks(marks2);
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;  // Output: -1 -1 -1 -1
    
    return 0;
}
