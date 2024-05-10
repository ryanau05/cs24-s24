#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
#include "Nodes.h"

class stack{
    public:
        AST* rpn[20];
        AST* root;
        int count;
        stack();
        ~stack();
        void recursiveClear(AST* token);
        void print();
        void print1(AST* token);
        void pushNeg(node* token);
        void pushOpp(node* token);
        void push(node* token);
        AST* pop();
};

#endif