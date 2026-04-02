#include <stdlib.h>
#include "BinaryExpressionTree.h"
#include "Queue.h"
#include "Stack.h"
#include "BinaryNode.h"
#include "HashTable.h"
#include "operators/Operator.h"
#include "operators/Addition.h"
#include "operators/Subtraction.h"
#include "operators/Multiplication.h"
#include "operators/Division.h"
#include "operators/Exponentiation.h"

BinaryExpressionTree::BinaryExpressionTree(Queue& in_queue) {

  head = nullptr;

  hashTable = HashTable();

  hashTable.insert(new Addition());
  hashTable.insert(new Subtraction());
  hashTable.insert(new Multiplication());
  hashTable.insert(new Division());
  hashTable.insert(new Exponentiation());

  Queue postFix = infixToPostfix(in_queue);

  int i = 0;

  BinaryNode* nodeArray[80];

  while (postFix.peek()) {
    const char* token = postFix.peek();
    BinaryNode* newNode = new BinaryNode(token);
    nodeArray[i] = newNode;

    if (i >= 2 && getTokenType(token) == OPERATOR) {
      BinaryNode* leftNode = nodeArray[i-2];
      BinaryNode* rightNode = nodeArray[i-1];
      newNode->left = leftNode;
      newNode->right = rightNode;
      nodeArray[i-2] = newNode;
      i -= 2;
    }

    i++;
    postFix.dequeue();
  }

  head = nodeArray[0];
}

BinaryExpressionTree::~BinaryExpressionTree() {
  RecursiveDeallocate(head);
}
    
void BinaryExpressionTree::printAsPrefix() {

}

void BinaryExpressionTree::printAsInfix() {

}

void BinaryExpressionTree::printAsPostfix() {

}

double BinaryExpressionTree::getEval() {
  return 0;
}

Queue BinaryExpressionTree::infixToPostfix(Queue& in_queue) {

  Queue out_queue = Queue();
  Stack op_stack = Stack();

  while (in_queue.peek()) {

    const char* token = in_queue.peek();

    switch (getTokenType(token)) {
      case NUMBER: {
        out_queue.enqueue(token);
        break;
      }

      case OPERATOR: {
        Operator* stackOp;
        if (op_stack.peek()) { stackOp = hashTable.getOperator(*op_stack.peek()); }
        Operator* curOp = hashTable.getOperator(*token);
        
        // this is so ugly but i dont really care anymore
        while( op_stack.peek()
            && getTokenType(op_stack.peek()) != PARENTHESIS_LEFT
            && (stackOp->getPrecedence() > curOp->getPrecedence()
              || (stackOp->getPrecedence() == curOp->getPrecedence()
                && curOp->getAssociativity() == LEFT))) {
          out_queue.enqueue(op_stack.peek());
          op_stack.pop();
        }
        op_stack.push(token);
        break;
      }

      case PARENTHESIS_LEFT: {
        op_stack.push(token);
        break;
      }

      case PARENTHESIS_RIGHT: {
        while( op_stack.peek()
            && getTokenType(op_stack.peek()) != PARENTHESIS_LEFT) {
          out_queue.enqueue(op_stack.peek());
          op_stack.pop();
        }
        if (getTokenType(op_stack.peek()) == PARENTHESIS_LEFT) {
          op_stack.pop();
        }
        break;
      }

      default: {}

    }

    in_queue.dequeue();

  }

  while (op_stack.peek()) {
    out_queue.enqueue(op_stack.peek());
    op_stack.pop();
  }

  return out_queue;
  
}

std::ostream& BinaryExpressionTree::prefixRecursive(std::ostream& os, BinaryNode* nodePtr) {
  return os;
}

std::ostream& BinaryExpressionTree::infixRecursive(std::ostream& os, BinaryNode* nodePtr) {
  return os;
}

std::ostream& BinaryExpressionTree::postfixRecursive(std::ostream& os, BinaryNode* nodePtr) {
  return os;
}

int getEvalRecursive(BinaryNode* nodePtr) {
  return 0;
}

void BinaryExpressionTree::RecursiveDeallocate(BinaryNode* nodePtr) {
  if (!nodePtr) { return; }
  RecursiveDeallocate(nodePtr->left);
  RecursiveDeallocate(nodePtr->right);
  delete nodePtr;
}

TokenType BinaryExpressionTree::getTokenType(const char* token) {

  if (!token) {
    return INVALID;
  }

  if (hashTable.getOperator(*token) != nullptr) {
    return OPERATOR;
  }

  if (*token == '(') {
    return PARENTHESIS_LEFT;
  }

  if (*token == ')') {
    return PARENTHESIS_RIGHT;
  }

  char* endChar;

  strtod(token, &endChar);

  if (*endChar != '\0') {
    return INVALID;
  }

  return NUMBER;

}


