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

// struct num : public AST{
//     double data;
//     public:
//         AST* left = nullptr;
//         AST* right = nullptr;
        // num(double number) : data(number){};
        // std::string prefix() const override;
        // std::string postfix() const override;
        // double value() const override;
        // double getdata() const;
// };

// struct neg : public AST{
//     char data = '~';
//     public:
//         AST* left = nullptr;
//         AST* right = nullptr;
//         std::string prefix() const override;
//         std::string postfix() const override;
//         double value() const override;
//         char getdata() const;
// };

// struct opp : public AST{
//     char data;
//     public:
//         AST* left = nullptr;
//         AST* right = nullptr;
//         opp(char opperator) : data(opperator){};
//         std::string prefix() const override;
//         std::string postfix() const override;
//         double value() const override;
//         char getdata() const;
// };

#endif