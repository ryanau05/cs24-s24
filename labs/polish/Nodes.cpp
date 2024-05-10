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

std::string node::prefix()  const {
  return data + " " + left->prefix() + " " + right->prefix();
}
std::string node::postfix() const {
  return left->postfix() + " " + right->postfix() + " " + data;
}
double      node::value()   const {
  if (type == "num"){
    return stod(data);
  }
  double x = 0;
  if (type == "opp"){
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
      x += left->value() / right->value();
    }
    else if (data == "&"){
      x += fmod(left->value(), right->value());
    }
  }
  else if (type == "neg"){
     x *= -1;
  }
  return x;
}