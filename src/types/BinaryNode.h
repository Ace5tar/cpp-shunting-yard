
#ifndef BIN_NODE_H
#define BIN_NODE_H

struct BinaryNode{
  const char* data;
  BinaryNode* left;
  BinaryNode* right;

  BinaryNode(const char*& in_data) {
    data = in_data;
  }

  BinaryNode() {}
};

#endif
