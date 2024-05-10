#include "AST.h"
#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// If you want a different main function, write it here!
// This file won't be graded - do whatever you want.

int main() {
  // stack* temp = new stack;
  // temp->push(new node("12", "num"));
  // temp->push(new node("3", "num"));
  // temp->pushOpp(new node("+", "opp"));
  // temp->print();
  // std::cout << std::endl;
  // temp->push(new node("5", "num"));
  // temp->push(new node("4", "num"));
  // temp->pushOpp(new node("+", "opp"));
  // temp->print();
  // std::cout << std::endl;
  // temp->push(new node("2", "num"));
  // temp->pushOpp(new node("/", "opp"));
  // temp->print();
  // std::cout << std::endl;
  // temp->pushOpp(new node("*", "opp"));
  // temp->print();
  // std::cout << std::endl;

  // delete temp;

  AST* temp = AST::parse("12 3 + 5 4 + 2 / *");
  static_cast<void>(temp);

  return 0;
}