#include "Operator.h"

#ifndef DIVISION_H
#define DIVISION_H

class Division : public Operator {
  public:

    // Constructor
    Division() : Operator(
      3, // Precedence
      '/', // Representation
      LEFT // Associativity
    ) {}
    
    // Function of this operator
    double func(double a, double b) {
      return a / b; 
    }
};

#endif
