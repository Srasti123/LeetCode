#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
  if (x<0) {
    return false;
  }
  int reversed = 0, original = x;
  while (x > 0) {
    int digit = x % 10;
    reversed = reversed * 10 + digit;
    x/=10;
  }
  return original == reversed;
}
int main() {
  int x = 121;
  bool isPalindromeResult = isPalindrome(x);
  if(isPalindromeResult) {
    cout << x << "is a palindrome" << endl;
  } else {
    cout << x << "is not a palindrome" << endl;
  }
  return 0;
}