#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// Implement your Stack member functions here.
stack::stack(){
    count = 0;
}

stack::~stack(){
    for (int i = 0; i < count; i++){
        delete rpn[i];
    }
}

void stack::pushNum(num* token){
    rpn[count] = token;
    count++;
}

void stack::pushNeg(neg* token){
    token->left = rpn[count];
    rpn[count] = token;
}

void stack::pushOpp(opp* token){
    token->left = rpn[count - 1];
    token->right = rpn[count];
    pop();
}

void stack::pop(){
    delete rpn[count];
    count--;
}

// void stack::compute(opp* token){
//     token->left = rpn[count - 2];
//     token->right = rpn[count - 1];
//     // pop();
//     // pop();
//     // rpn[0] = token;
// }  

// void stack::negate(neg* token){
//     token->left = rpn[0];
//     rpn[1] = token;
//     pop();
// }