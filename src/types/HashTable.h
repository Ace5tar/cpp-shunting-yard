#include "operators/Operator.h"

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class HashTable {
  public:
    // Destructor
    ~HashTable();

    // Insert an operator to the internalArray
    int insert(Operator* in_operator);

    // Get the operator linked to the given character
    Operator* getOperator(char opChar);
  private:

    // Internal array used
    Operator* internalArray[256] = {nullptr};

    // Hashing value (uses but representation of the char)
    int hash(char opChar);
    int hash(Operator* in_operator);
    
};

#endif
