#include<bits/stdc++.h>
using namespace std;
void func(int i, int n) {
    if (i<1) return;   // Base condition
    func(i-1, n);  // Function to call print(n-1) integers
    cout<<i<<endl;
}
int main() {
    int n = 4;
    func(n,n);
    return 0;
}
