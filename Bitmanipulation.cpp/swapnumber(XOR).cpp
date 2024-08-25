#include <iostream>
using namespace std;

int main() {
    int x, y;

    // Taking input from the user
    cout << "Enter the first number (x): ";
    cin >> x;

    cout << "Enter the second number (y): ";
    cin >> y;

    // Displaying original values
    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    // XOR swap algorithm
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    // Displaying swapped values
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    return 0;
}
