#include "Nodes.h"
#include "AST.h"
#include "Stack.h"

#include <sstream>
#include <string>
#include <cmath>

// This creates the number format the autograder expects:
std::string format(double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}

node::node(std::string data_, std::string type_){
  data = data_;
  type = type_;
}

node::~node(){
  if (left != nullptr){
    delete left;
    right = nullptr;
  }
  if (right != nullptr){
    delete right;
    right = nullptr;
  }
}

std::string node::prefix()  const {
  if (left == nullptr && right == nullptr){
    return data;
  }
  else if (right == nullptr){
    return data + " " + left->prefix();
  }
  return data + " " + left->prefix() + " " + right->prefix();
}
std::string node::postfix() const {
  if (left == nullptr && right == nullptr){
    return data;
  }
  else if (right == nullptr){
    return left->postfix() + " " + data;
  }
  return left->postfix() + " " + right->postfix() + " " + data;
}
double      node::value()   const {
  double x = 0;
  if (type == "num"){
    return stod(data);
  }
  else if (left == nullptr && right == nullptr){
    return 0;
  }
  else if (type == "opp"){
    if (data == "+"){
        x += left->value() + right->value();
    }
    else if (data == "-"){
      x += left->value() - right->value();
    }
    else if (data == "*"){
      x +=left->value() * right->value();
    }
    else if (data == "/"){
      if (right->value() == 0){
        throw std::runtime_error("Division by zero.");
      }
      x += left->value() / right->value();
    }
    else if (data == "%"){
      if (right->value() == 0){
        throw std::runtime_error("Division by zero.");
      }
      x += fmod(left->value(), right->value());
    }
  }
  else if (type == "neg"){
    if (left != nullptr){
      x += -1 * left->value();
    }
  }
  return x;
}