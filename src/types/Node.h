
#ifndef NODE_H
#define NODE_H

struct Node{
  const char* data;
  Node* next;

  Node(const char*& in_data) {
    data = in_data;
  }

  Node() {}

  ~Node() {
    delete[] data;
  }

};

#endif
