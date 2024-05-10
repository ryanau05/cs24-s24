#include "Nodes.h"
#include "AST.h"
#include "Stack.h"

#include <sstream>
#include <string>

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
  return "";
}
std::string node::postfix() const {
  return "";
}
double      node::value()   const {
  return 0;
}