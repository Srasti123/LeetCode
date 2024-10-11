#include <iostream>
#include <vector>
using namespace std;

void updateArray(vector<int>& arr) {
    int n = arr.size();
    
    // Iterate through the array except the last element
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] < arr[i]) {
            arr[i] = arr[i + 1];
        } else {
            arr[i] = -1;
        }
    }
    
    // The last element is always -1
    arr[n - 1] = -1;
}

int main() {
    // Example 1
    vector<int> arr1 = {4, 2, 1, 5, 3};
    updateArray(arr1);
    for (int i : arr1) {
        cout << i << " ";
    }
    cout << endl;  // Output: 2 1 -1 3 -1
    
    // Example 2
    vector<int> arr2 = {5, 6, 2, 3, 1, 7};
    updateArray(arr2);
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;  // Output: -1 2 -1 1 -1 -1
    
    return 0;
}
