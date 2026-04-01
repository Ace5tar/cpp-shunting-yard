#include "Operator.h"

#ifndef ADDITION_H
#define ADDITION_H

class Addition : public Operator {
  public:

    // Constructor
    Addition() : Operator(
      2, // Precedence
      '+', // Representation
      LEFT // Associativity 
    ) {}

    // Function of this operator
    double func(double a, double b) {
      return a + b; 
    }
};

#endif
