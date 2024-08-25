#include <iostream>
using namespace std;
int main() {
    int num;
    //Input a number
    cout << "Enter a numer: ";
    cin >> num;
    if (num & (1 << 0)) {
        cout << "The first bit is set (1)." << endl;
    } else {
        cout << "The first bit is unset (0)." << endl;

    }
    return 0;
}