#include "Operator.h"

#ifndef SUBTRACTION_H 
#define SUBTRACTION_H

class Subtraction : public Operator {
  public:

    // Constructor
    Subtraction() : Operator(
      2, // Precedence
      '-', // Representation
      LEFT // Associativity
    ) {}
    
    // Function of this operator
    double func(double a, double b) {
      return a - b; 
    }
};

#endif
