#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1e6 + 1;

int main() {
  int n;
  cin>>n;
  vector<int> divCount(MAX, 0);

  for(int i=1; i<MAX; i++){
    for (int j=i; j<MAX; j+=i){
      divCount[j]++;
    }
  }
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    cout << divCount[x] << "\n";
  }
  return 0;
}
