
#ifndef OPERATOR_H
#define OPERATOR_H

enum Associativity {
  LEFT,
  RIGHT
};

class Operator {
  public:

    // The function that the operator does, must be defined in child
    virtual double func(double a, double b) = 0;

    // Return the precendence of this operator
    int getPrecedence();

    // Return the representation of this operator
    char getRepresentation();

    // Return the ossociativity for this operator
    Associativity getAssociativity();

  private:

    // The precendence of this operator, defined once in header file
    int precedence;

    // The representation of this operator, defined once in header file
    char representation;
    
    // The associativity of this operator, defined once in header file
    Associativity associativity;

};

#endif
