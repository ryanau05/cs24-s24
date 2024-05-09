#include "AST.h"
#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// If you want a different main function, write it here!
// This file won't be graded - do whatever you want.

int main() {
  stack* temp = new stack;
  temp->push(new node("12", "num"));
  // temp->pushNum(new num(3));
  // temp->pushOpp(new opp('+'));
  // opp* token = dynamic_cast<opp*>(temp->rpn[temp->count - 1]);
  // num* token1 = dynamic_cast<num*>(token->right);
  // std::cout << token1->getdata() << std::endl;
  temp->pushNeg(new node("~", "neg"));
  delete temp;
  return 0;
}