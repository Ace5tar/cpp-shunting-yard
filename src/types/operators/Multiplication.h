#include "Operator.h"

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

class Multiplication : public Operator {
  public:

    // Constructor
    Multiplication() : Operator(
      3, // Precedence
      '*', // Representation
      LEFT // Associativity
    ) {}
    
    // Function of this operator
    double func(double a, double b) {
      return a * b; 
    }
};

#endif
