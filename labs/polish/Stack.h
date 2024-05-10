#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
#include "Nodes.h"

class stack{
    public:
        // AST* rpn[20];
        // AST* root;
        // int count;
        // stack();
        // ~stack();
        void print();
        void print1(AST* token);
        // void pushNeg(node* token);
        // void pushOpp(node* token);
        // void push(node* token);
        // AST* pop();
        // std::string PN(AST* token) const;
        // std::string RPN(AST* token) const;


        int top;
        AST* data[20];

        stack();
        ~stack();
        void pushNum(node* token);
        void pushOpp(node* token);
        void pushNeg(node* token);
        void pop();
        AST* topNode();
        void recursiveClear(AST* token);
};

#endif