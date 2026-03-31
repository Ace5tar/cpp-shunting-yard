#include <cmath>
#include "Operator.h"

#ifndef EXPONENTIATION_H 
#define EXPONENTIATION_H

class Exponentiation : Operator {
  public:
    // Function of this operator
    double func(double a, double b) {
      return std::pow(a, b); 
    }

  private:

    // Precedence of this operator
    int precedence = 4;

    // Representation of this operator
    char representation = '^';

    // Associativity of this operator
    Associativity associativity = RIGHT;
};

#endif
