#include <bits/stdc++.h> 
using namespace std;

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x, min});
    }

    void pop() {
      if (!st.empty()) {
        st.pop();
      } else {
        cout << "Stack is empty, cannot pop." << endl;
      }
    }

    int top() const {
      if (!st.empty()) {
        return st.top().first;
      } else {
        cout << "Stack is empty, no top element." << endl;
        return -1; 
      }
    }

    int getMin() const {
      if (!st.empty()) {
        return st.top().second;
      } else {
        cout << "Stack is empty, no minimum element." << endl;
        return -1; 
      }
    }
};
