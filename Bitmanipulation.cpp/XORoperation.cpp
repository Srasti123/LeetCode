#include <iostream>
using namespace std;

int main() {
    int num1, num2, result;

    // Taking input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Applying XOR operation
    result = num1 ^ num2;

    
    cout << "The result of " << num1 << " XOR " << num2 << " is: " << result << endl;

    return 0;
}

