#include <iostream>
#include "types/Stack.h"

int main() {
  Stack stack;

  stack.push("test");

  std::cout << stack.peek() << std::endl;
}
