#include <iostream>
#include "HashTable.h"
#include "Queue.h"
#include "BinaryNode.h"

#ifndef BIN_EXPR_TREE_H
#define BIN_EXPR_TREE_H

enum TokenType {
  NUMBER,
  OPERATOR,
  PARENTHESIS_LEFT,
  PARENTHESIS_RIGHT,
  INVALID
};

class BinaryExpressionTree {
  public:

    // Constructor, takes a queue of tokens in infix notation
    BinaryExpressionTree(Queue& in_queue);

    // Destructor
    ~BinaryExpressionTree();
    
    // Print the expression tree in prefix notation
    void printAsPrefix();

    // Print the expression tree in infix notation
    void printAsInfix();

    // Print the expression tree in postfix notation
    void printAsPostfix();

    // Evaluate the expression tree and return the result
    double getEval();


  private:

    // Converts a queue of tokens in infix notation to a queue of tokens in postfix notation
    // This is where the shunting yard algorirhm is!!
    Queue infixToPostfix(Queue& in_queue);

    // Head node of the binary tree
    BinaryNode* head;

    // Internal hash table used for operators
    HashTable hashTable;

    // Recursive algorithm for generating an output stream of the expression tree in prefix notation
    std::ostream& prefixRecursive(std::ostream& os, BinaryNode* nodePtr);

    // Recursive algorithm for generating an output stream of the expression tree in infix notation
    std::ostream& infixRecursive(std::ostream& os, BinaryNode* nodePtr);

    // Recursive algorithm for generating an output stream of the expression tree in postfix notation
    std::ostream& postfixRecursive(std::ostream& os, BinaryNode* nodePtr);

    // Recursive algorithm for evaluating the expression
    int getEvalRecursive(BinaryNode* nodePtr);

    // Recursive algorithm to dealloate memory for nodes
    void RecursiveDeallocate(BinaryNode* nodePtr);

    // Get the type of token that the given cstring is
    TokenType getTokenType(const char* token);

};


#endif
