#include "Node.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
  public:

    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Add an item to the end of the queue
    int enqueue(const char* in_data);

    // Remove the item at the front of the queue
    int dequeue();

    // Return the item at the front of the queue
    const char* peek();

  private:

    // Recursive deallocation method for linked list implementation
    void RecursiveDeallocate(Node* node);

    // First node of the linked list implementation
    // Acts as the front of the queue
    Node* head;

    // Last node of the linked list implementation
    // Acts as the end of the queue
    Node* last;

};

#endif
