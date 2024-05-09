#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
using namespace std;

class stack{
    int count = 0;

    public:
        AST* rpn[20];
        stack();
        ~stack();
        void push(AST* token);
        void pop();
        void compute();
        void negate();
};

#endif