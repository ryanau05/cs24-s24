#ifndef NODES_H
#define NODES_H

#include "AST.h"
#include <cmath>

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.
class num : public AST{
    double data;
    public:
        num(double number) : data(number){};
        std::string prefix() const override;
        std::string postfix() const override;
        double value() const override;
        double getdata() const;
};

struct neg : public AST{
    char data = '~';
    AST* left = nullptr;
    public:
        std::string prefix() const override;
        std::string postfix() const override;
        double value() const override;
        char getdata() const;
};

struct opp : public AST{
    char data;
    AST* left = nullptr;
    AST* right = nullptr;;
    public:
        opp(char opperator) : data(opperator){};
        std::string prefix() const override;
        std::string postfix() const override;
        double value() const override;
        char getdata() const;
};

#endif