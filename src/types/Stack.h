
#ifndef STACK_H
#define STACK_H

// Thy data type for the kind of data put in the stack
class Stack {
  public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Push a value to the stop of the stack
    int push(const char* in_data);

    // Remove the top value of the stack
    int pop();

    // Return the value on the top of the stack
    const char* peek();

    // Return whether or not the stack is empty
    bool isEmpty();

  private:
    // Single node for linked list implementation
    struct Node {
      const char* data;
      Node* next;
    };

    // Head of the linked list implementation
    Node* head;

    // Recursive deallocation function
    void RecursiveDeallocate(Node* node);
};

#endif
