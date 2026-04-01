#include <iostream>
#include "types/Stack.h"
#include "types/Queue.h"
#include "types/HashTable.h"
#include "types/operators/Addition.h"
#include "types/operators/Subtraction.h"
#include "types/operators/Multiplication.h"
#include "types/operators/Division.h"
#include "types/operators/Exponentiation.h"

/* Construct the main hashTable with all of the operators */
void constructHashTable(HashTable& hashTable);

/* Parse the given input into a queue of tokens */
Queue parseInput(char* rawInput);

int main(int argc, char* argv[]) {

  HashTable hashTable = HashTable();
  constructHashTable(hashTable);

  char* in = new char[80];
  std::cin.getline(in, 80);

  Queue parsed = parseInput(in);

  while (parsed.peek()) {
    std::cout << parsed.peek() << std::endl;
    parsed.dequeue();
  }

  delete in;

  return 0;
}

void constructHashTable(HashTable& hashTable) {

  // Insert one of each operator type to the given hashTable
  hashTable.insert(new Addition());
  hashTable.insert(new Subtraction());
  hashTable.insert(new Multiplication());
  hashTable.insert(new Division());
  hashTable.insert(new Exponentiation());

}


Queue parseInput(char* rawInput) {

  Queue queue = Queue(); 

  int inputIndex = 0;
  bool continueParsing = true;

  while (continueParsing) {
    
    char* charPtr = rawInput + inputIndex;

    // If character is whitespace, replace with null terminator
    if (*charPtr == ' ') {
      *charPtr = '\0';
    } 

    // If character is null terminator, end parsing
    else if (*charPtr == '\0') {
      continueParsing = false;
    }

    // If character is start of token, add ptr to character to queue
    else if (inputIndex == 0 || *(charPtr - 1) == '\0') {
      queue.enqueue(charPtr);
    }

    ++inputIndex;

  }

  return queue;

}
