#include <bits/stdc++.h>
using namespace std;
void printFrequency(vector<int>& arr) {
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int count = 1;
  for (int i = 1; i<=n; i++) {
    if(arr[i] == arr[i-1]) {
      count++;
    } else {
      cout << arr[i-1] << "occurs" << count << "times\n";
      count = 1;
    }
  }
  cout << arr[n-1] << "occurs" << count << "times\n";
}
int main() {
  vector<int> arr = {10,20,20,10,10,20,30};
  printFrequency(arr);
  return 0;
}