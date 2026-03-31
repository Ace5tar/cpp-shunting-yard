#include "Operator.h"

#ifndef ADDITION_H
#define ADDITION_H

class Addition : Operator {
  public:
    // Function of this operator
    double func(double a, double b) {
      return a + b; 
    }

  private:

    // Precedence of this operator
    int precedence = 2;

    // Representation of this operator
    char representation = '+';

    // Associativity of this operator
    Associativity associativity = LEFT;
};

#endif
