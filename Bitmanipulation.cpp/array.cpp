#include <iostream>
using namespace std;
int main() {
    int numbers[5];  //Create an array
    numbers[0] = 12;  // Initialising an array
    numbers[1] = 15;
    numbers[2] = 18;
    numbers[3] = 40;
    numbers[4] = 13;
    for(int i=0; i<5; i++) {
        cout << "Element at index: " << i <<" : "<< numbers[i] << endl;
    }
    return 0;

    
}