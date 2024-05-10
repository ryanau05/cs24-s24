#ifndef NODES_H
#define NODES_H

#include "AST.h"
#include <cmath>

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.

class node : public AST{
    public:
        std::string data;
        std::string type;
        node(std::string data_, std::string type_);
        AST* left = nullptr;
        AST* right = nullptr;
        std::string prefix() const override;
        std::string postfix() const override;
        double value() const override;
};

#endif