#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Function perform preorder traversal and store value in 'arr' 
void preorder(Node* root, vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  arr.push_back(root->data); // Push current node's value into the vector
  preorder(root->left,arr);
  preorder(root->right,arr);
}
// Function to initiate preorder traversal and return vector
vector<int> preOrder(Node* root) {
  vector<int> arr; // Create an empty vector to store preorder traversal value
  preorder(root,arr);
  return arr;
}
int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  vector<int> result = preOrder(root);
  cout << "Preorder Traversal:";
  for (int val: result) {  // Output each value in the preorder traversal
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
