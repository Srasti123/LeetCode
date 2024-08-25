#include <iostream>
using namespace std;

int main() {
    int num = 8; // 8 in binary is 0000 1000

    // Left shift operation
    int leftShift = num << 1; // Shift bits of 'num' left by 1 position
    
    // Right shift operation
    int rightShift = num >> 1; // Shift bits of 'num' right by 1 position

    cout << "Original number: " << num << endl;
    cout << "After left shift by 1: " << leftShift << endl;
    cout << "After right shift by 1: " << rightShift << endl;

    return 0;
}
