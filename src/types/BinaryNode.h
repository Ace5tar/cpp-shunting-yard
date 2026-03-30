
#ifndef BIN_NODE_H
#define BIN_NODE_H

struct Node{
  const char* data;
  Node* left;
  Node* right;

  Node(const char*& in_data) {
    data = in_data;
  }

  Node() {}

  ~Node() {
    delete[] data;
  }

};

#endif
