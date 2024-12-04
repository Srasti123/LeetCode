#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
  if (n<=0) {
    return false;
  }
  return (n&(n-1)) == 0;
}
int main() {
  int n = 16;
  bool isPowerOfTwoResult = isPowerOfTwo(n);
  if(isPowerOfTwoResult) {
    cout << n << "is a Power of 2" << endl;
  } else {
    cout << n << "is not a power of 2" << endl;
  }
  return 0;
}