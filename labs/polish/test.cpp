#include "AST.h"
#include "Stack.h"
#include <iostream>
#include "Nodes.h"

// If you want a different main function, write it here!
// This file won't be graded - do whatever you want.

int main() {
  stack* temp = new stack();
  AST* token1 = new num(1);
  AST* token2 = new num(2);

  temp->push(token1);
  temp->push(token2);

  delete token1;
  delete token2;
  delete temp;

  return 0;
}