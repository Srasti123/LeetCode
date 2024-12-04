#include<bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode (int x) : val(x), next(nullptr) {}
};
// Function to reverse the sublist
ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || left == right)
     return head;
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* prev = dummy;
  for (int i = 1; i < left; ++i) {
    prev = prev->next;

  }
  ListNode* curr = prev->next;
  ListNode* next = nullptr;
  for(int i = 0; i < right-left; ++i) {
    next = curr->next;
    curr->next = next->next;
    next->next = prev->next;
    prev->next = next;
  }
  return dummy->next;
}
void printList(ListNode* head) {
  while(head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
int main() {
  ListNode* head = new ListNode(1);
  head->next  = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  int left = 2, right = 4;
  head = reverseBetween(head, left, right);
  printList(head);
  return 0;
}