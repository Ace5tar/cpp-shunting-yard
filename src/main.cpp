#include <iostream>
#include "types/Stack.h"
#include "types/Queue.h"
#include "types/BinaryExpressionTree.h"

/* Parse the given input into a queue of tokens */
Queue parseInput(char* rawInput);


int main(int argc, char* argv[]) {

  char* in = new char[80];
  std::cin.getline(in, 80);

  Queue parsed = parseInput(in);

  BinaryExpressionTree exprTree = BinaryExpressionTree(parsed);

  delete in;

  return 0;
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
















