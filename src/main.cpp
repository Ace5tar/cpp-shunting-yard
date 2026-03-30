#include <iostream>
#include "types/Stack.h"
#include "types/Queue.h"

int main(int argc, char* argv[]) {
  Queue queue = Queue();
  Stack stack = Stack();

  queue.enqueue(new const char[80]{"q1"});
  queue.enqueue(new const char[80]{"q2"});
  queue.enqueue(new const char[80]{"q3"});

  stack.push(new const char[80]{"s1"});
  stack.push(new const char[80]{"s2"});
  stack.push(new const char[80]{"s3"});

  std::cout << queue.peek() << std::endl;
  queue.dequeue();
  std::cout << queue.peek() << std::endl;
  queue.dequeue();
  std::cout << queue.peek() << std::endl;

  std::cout << stack.peek() << std::endl;
  stack.pop();
  std::cout << stack.peek() << std::endl;
  stack.pop();
  std::cout << stack.peek() << std::endl;
}
