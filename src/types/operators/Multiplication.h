#include "Operator.h"

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

class Multiplication : Operator {
  public:
    // Function of this operator
    double func(double a, double b) {
      return a * b; 
    }

  private:

    // Precedence of this operator
    int precedence = 3;

    // Representation of this operator
    char representation = '*';

    // Associativity of this operator
    Associativity associativity = LEFT;
};

#endif
