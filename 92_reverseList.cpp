/*反转链表 */
#include <iostream>

struct Node {
  int val;
  Node* next;
};
Node* reverseList(Node* head) {
  if (head == nullptr) {
    return head;
  }
  Node* pre = head;
  Node* cur = pre->next;
  Node* next;
  while (cur) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  head->next = nullptr;
  head = pre;
  return head;
}

