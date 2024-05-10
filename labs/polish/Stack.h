#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
#include "Nodes.h"

class stack{
    public:
        AST* rpn[20];
        int count;
        stack();
        ~stack();
        void recursiveClear(AST* token);
        void print();
        void print1(AST* token);
        // void pushNum(num* token);
        void pushNeg(node* token);
        void pushOpp(node* token);
        void push(node* token);
        void pop();
        // string getType(AST* token);
};

#endif