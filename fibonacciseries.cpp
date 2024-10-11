#include<iostream>
using namespace std;
int fibonacci(int N) {
    if (N<=1)   // Base condition
    {
        return N;
    }
    // Problem breakdown into 2 functional calls 
    int last = fibonacci(N-1);
    int slast = fibonacci(N-2);
    return last+slast;
} 
int main() {
    int N = 4;
    cout<<fibonacci(N)<<endl;
    return 0;
}