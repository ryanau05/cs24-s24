#include "Nodes.h"
#include "AST.h"

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

std::string node::prefix() const{
  return "";
}

std::string node::postfix() const{
  return "";
}

double node::value() const{
  return 0;
}

// std::string num::prefix() const{
//   return "";
// }

// std::string num::postfix() const{
//   return "";
// }

// double num::value() const{
//   return 0;
// }

// double num::getdata() const{
//   return data;
// }

// std::string neg::prefix() const{
//   return "";
// }

// std::string neg::postfix() const{
//   return "";
// }

// double neg::value() const{
//   return 0;
// }

// char neg::getdata() const{
//   return data;
// }

// std::string opp::prefix() const{
//   return "";
// }

// std::string opp::postfix() const{
//   return "";
// }

// double opp::value() const{
//   return 0;
// }

// char opp::getdata() const{
//   return data;
// }

// Implement your AST subclasses' member functions here.