#include "Stack.h"

Stack::Stack() {
  head = new Node();
  head->next = nullptr;
}

Stack::~Stack() {
  RecursiveDeallocate(head);
}

void Stack::RecursiveDeallocate(Node* node) {
  if (!node->next) {return;}
  RecursiveDeallocate(node->next);
  delete node->data;
  delete node;
}

int Stack::push(const char* in_data) {
  Node* node = new Node();
  node->data = in_data;
  node->next = head->next;
  head->next = node;
  
  return 0;
}

int Stack::pop() {
  Node* temp = head->next;
  head->next = temp->next;
  delete temp;

  return 0;
}

const char* Stack::peek() {
  return head->next->data;
}
