#include "Operator.h"

int Operator::getPrecedence() {
  return precedence;
}

char Operator::getRepresentation() {
  return representation;
}

Associativity Operator::getAssociativity() {
  return associativity;
}
