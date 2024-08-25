#include <iostream>
using namespace std;
int main() {
    int num, bitPosition;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter a bit position: ";
    cin >> bitPosition;
    int mask = 1 << bitPosition;
    if (num & mask) {
        cout << "The bit at position "<< bitPosition << ""
    }


}