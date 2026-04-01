#include <iostream>
#include "types/Stack.h"
#include "types/Queue.h"
#include "types/HashTable.h"
#include "types/operators/Addition.h"
#include "types/operators/Subtraction.h"
#include "types/operators/Multiplication.h"
#include "types/operators/Division.h"
#include "types/operators/Exponentiation.h"

int main(int argc, char* argv[]) {
  HashTable hashTable = HashTable();

  hashTable.insert(new Addition());
  hashTable.insert(new Subtraction());
  hashTable.insert(new Multiplication());
  hashTable.insert(new Division());
  hashTable.insert(new Exponentiation());

  std::cout << " 3 + 2 = " << hashTable.getOperator('+')->func(3, 2) << std::endl;
  std::cout << " 9 - 4 = " << hashTable.getOperator('-')->func(9, 4) << std::endl;
  std::cout << " 5 * 3 = " << hashTable.getOperator('*')->func(5, 3) << std::endl;
  std::cout << " 3 / 2 = " << hashTable.getOperator('/')->func(3, 2) << std::endl;
  std::cout << " 2 ^ 3 = " << hashTable.getOperator('^')->func(2, 3) << std::endl;

  return 0;
}
