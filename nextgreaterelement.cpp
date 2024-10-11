#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n) {
    // Create a vector to store the result, initialized with -1
    vector<int> result(n, -1);
    stack<int> s; // Stack to store elements
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are smaller than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        
        // If the stack is not empty, the top of the stack is the next greater element
        if (!s.empty()) {
            result[i] = s.top();
        }
        
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();
    
    vector<int> result = nextGreaterElement(arr, n);
    
    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
