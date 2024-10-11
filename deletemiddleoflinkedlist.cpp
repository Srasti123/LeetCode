#include<bits/stdc++.h>
using namespace std;
void deleteMiddleUtil(std::stack<int>& s, int currentIndex, int midIndex) {
    if (current index == midIndex) {
        s.pop();
        return;
    }
    int topElement = s.top();
    s.pop();
    deleteMiddleUtil(s, currentIndex + 1, midIndex);
    s.push(topElement);
}
void deleteMiddle(std::stack<int>& s) {
    int size = s.size0();
    
    int midIndex = size / 2;
    deleteMiddleUtil(s, 0, midIndex);

}
void printStack(std::)