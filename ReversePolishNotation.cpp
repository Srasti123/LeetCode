#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int evalRPN(vector<string>& tokens) {
  stack<int> st;
  for (string token : tokens) {
    if (isdigit(token[0])) {
      st.push(stoi(token));
    } else {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      if (token == "+") {
        st.push(a+b);
      } else if (token == "-") {
        st.push(a-b);
      } else if (token == "*") {
        st.push(a*b);
      } else {
        st.push(a/b);
      }
    }
  }
  return st.top();
}
int main() {
  vector<string> tokens = {"2","1","+","3","*"};
  int result = evalRPN(tokens);
  cout << "Result:" << result << endl;
  return 0;
}