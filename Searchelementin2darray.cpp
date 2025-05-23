#include <iostream>
using namespace std;
bool staircaseSearch(int arr[][4], int rows, int cols, int target) {
    int i = 0, j = cols - 1; 
    while (i < rows && j >= 0) {
        if (arr[i][j] == target) {
            cout << "Element found at: (" << i << ", " << j << ")\n";
            return true;
        }
        if (arr[i][j] > target)
            j--; 
        else
            i++; 
    }
    cout << "Element not found\n";
    return false;
}
int main() {
    int arr[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    
    int target = 29;
    staircaseSearch(arr, 4, 4, target);
    return 0;
}
