#include <iostream>
using namespace std;

void updateArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            arr[i] = arr[i + 1]; 
        } else {
            arr[i] = -1; 
        }
    }
    arr[n - 1] = -1; 
}
int main() {
    int n;
    cin >> n; 
    int arr[n]; 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    updateArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

