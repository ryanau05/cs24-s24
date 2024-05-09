#include "Stack.h"
#include "Nodes.h"

// Implement your Stack member functions here.
stack::stack(){

}

stack::~stack(){
    for (int i = 0; i < count; i++){
        delete rpn[i];
    }
}

void stack::push(AST* token){
    rpn[count] = token;
    count++;

    if (neg* token1 = dynamic_cast<neg*>(token)){
        negate();
    }
    else if (num* token1 = dynamic_cast<num*>(token); token1 == nullptr){
        compute();
    }
}

void stack::pop(){
    delete rpn[count];
    count--;
}

void stack::compute(){
    opp* token = dynamic_cast<opp*>(rpn[count]);
    token->left = rpn[count - 2];
    token->right = rpn[count - 1];
    rpn[count - 2] = token;
    pop();
    pop();
}  

void stack::negate(){
    neg* token = dynamic_cast<neg*>(rpn[count]);
    token->left = rpn[count - 1];
    rpn[count - 1] = token;
    pop();
}