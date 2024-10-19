#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n) {
    vector<int> result(n, -1);
    stack<int> s; 
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();
    vector<int> result = nextGreaterElement(arr, n);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
