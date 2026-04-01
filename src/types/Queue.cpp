#include <iostream>
#include "Queue.h"

Queue::Queue() {
  head = new Node();
  head->next = nullptr;
  last = head;
}

Queue::~Queue() {
  RecursiveDeallocate(head->next);
  delete head->data;
}

void Queue::RecursiveDeallocate(Node* node) {
  if (!node) { return; }
  RecursiveDeallocate(node->next);
  delete node;
}

int Queue::enqueue(const char* in_data) {
  Node* newNode = new Node(in_data);
  last->next = newNode;
  last = newNode;

  return 0;
}

int Queue::dequeue() {
  Node* temp = head->next->next;
  delete head->next;
  head->next = temp;

  return 0;
}

const char* Queue::peek() {
  if (head->next == nullptr) { return nullptr; }
  return head->next->data;
}
