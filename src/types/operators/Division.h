#include "Operator.h"

#ifndef DIVISION_H
#define DIVISION_H

class Division : Operator {
  public:
    // Function of this operator
    double func(double a, double b) {
      return a / b; 
    }

  private:

    // Precedence of this operator
    int precedence = 3;

    // Representation of this operator
    char representation = '/';

    // Associativity of this operator
    Associativity associativity = LEFT;
};

#endif
