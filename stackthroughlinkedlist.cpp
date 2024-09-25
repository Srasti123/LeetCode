#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class stack {
private:
    Node* top;
public:
    stack() {
        top = nullptr;
    }
    bool isempty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << "pushed to stack."<<endl;
    }
    void pop() {
        if ("isEmpty"()) {
            cout << "Stack unerflow! No elements to pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << "popped from stack." << endl;
        delete temp;
    }
    int peel

