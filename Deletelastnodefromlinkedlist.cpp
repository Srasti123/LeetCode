#include<bits/stdc++.h>

class Node {
public:
    int data;         
    Node* next;  

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    temp->next = nullptr;
    return head;
}
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head = deleteTail(head);
    printLL(head);
}