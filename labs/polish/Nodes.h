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
        ~node();
        AST* left = nullptr;
        AST* right = nullptr;
        virtual std::string prefix()  const override;
        virtual std::string postfix() const override;
        virtual double      value()   const override;
};

#endif