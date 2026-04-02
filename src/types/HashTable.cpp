#include "HashTable.h"
#include "operators/Operator.h"

HashTable::~HashTable() {
  for (int i = 0; i < 256; i++) {
    if (internalArray[i]) {
      delete internalArray[i];
    }
  }
}

int HashTable::hash(Operator* in_operator) {
  return (int)(in_operator->getRepresentation());
}

int HashTable::hash(const char opChar) {
  return (int)opChar;
}

int HashTable::insert(Operator* in_operator) {

  internalArray[hash(in_operator)] = in_operator;

  return 0;
}

Operator* HashTable::getOperator(const char opChar) {
  return internalArray[hash(opChar)];
}
