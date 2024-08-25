#include <iostream>
using namespace std;
int main() {
    // Initialize the array
    int numbers[] = {10, 20, 30, 40, 50};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    // Initialize the max and min of the array
    int max = numbers[0];
    int min = numbers[0];
    // Iterate through for loop
    for (int i = 1; i<n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    cout << "Maximum element: "<<max <<endl;
    cout << "Minimum element: "<<min <<endl;
    return 0;
}