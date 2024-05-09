#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
#include "AST.h"
#include "Nodes.h"
using namespace std;

class stack{
    public:
        AST* rpn[20];
        int count;
        stack();
        ~stack();
        void pushNum(num* token);
        void pushNeg(neg* token);
        void pushOpp(opp* token);
        void pop();
        void compute(opp* token);
        void negate(neg* token);
};

#endif