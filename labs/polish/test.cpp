#include "AST.h"
#include "Stack.h"
#include <iostream>
#include "Nodes.h"

// If you want a different main function, write it here!
// This file won't be graded - do whatever you want.

int main() {
  // stack* temp = new stack();
  // AST* token1 = new num(1);
  // AST* token2 = new num(2);
  // AST* token3 = new opp('*');

  // temp->push(token1);
  // temp->push(token2);
  // temp->push(token3);
  AST* temp;
  // temp->parse("12 3 + 5 4 + 2 / *");
  temp->parse("12 3 *");

  return 0;
}