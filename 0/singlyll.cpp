#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};
class Operations {
  private:
      Node* head;
  public:
      Operations() {
        head = NULL;
      }
      void insert_end(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
          head = newNode;
        } else {
          Node* temp = head;
          while(temp->next != NULL) {
            temp = temp-> next;
          }
          temp->next = newNode;
        }
      }
      void insert_beginning(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
          head = newNode;
        } else {
          newNode->next = head;
          head = newNode;
        }
      }
      void delete_val(int value) {
        if(head == NULL){
          return;
        }
        if(head->data == value){
          Node* temp = head;
          head = head->next;
          delete temp;
          return;
        }
      }
      void traversal(){
        Node* temp = head;
        while(temp != NULL){
          cout << temp->data <<" ";
          temp = temp->next;
        }
      }
}