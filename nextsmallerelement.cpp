#include<bits/stdc++.h>
using namespace std;


void nextSmallerElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);   
    stack<int> s;         

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            nse[i] = -1;
        } else {
            nse[i] = s.top();
        }
        s.push(arr[i]);
    }
    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nse[i] << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> arr1 = {4, 8, 5, 2, 25};
    cout << "Input: [4, 8, 5, 2, 25]" << endl;
    nextSmallerElement(arr1);
    vector<int> arr2 = {13, 7, 6, 12};
    cout << "Input: [13, 7, 6, 12]" << endl;
    nextSmallerElement(arr2);
}
