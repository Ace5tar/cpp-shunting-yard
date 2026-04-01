#include <cmath>
#include "Operator.h"

#ifndef EXPONENTIATION_H 
#define EXPONENTIATION_H

class Exponentiation : public Operator {
  public:

    // Constructor
    Exponentiation() : Operator(
      4, // Precedence
      '^', // Representation
      RIGHT // Associativity
    ) {}
    
    // Function of this operator
    double func(double a, double b) {
      return std::pow(a, b); 
    }
};

#endif
