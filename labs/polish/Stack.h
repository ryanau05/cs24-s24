#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
#include "Nodes.h"

class stack{
    public:
        int top;
        AST* rpn[20];
        stack();
        ~stack();
        void pushNum(node* token);
        void pushOpp(node* token);
        void pushNeg(node* token);
        void pop();
        AST* topNode();
        void clear();
        void recursiveClear(AST* token);
        void clearStack();
        void print() const;
        void print1(AST* token) const;
        bool isEmpty();
};

#endif