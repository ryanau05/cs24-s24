#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// Implement your Stack member functions here.
stack::stack(){
    count = 0;
}

stack::~stack(){
    if (count > 0){
        for (int i = 0; i < count; i++){
            recursiveClear(rpn[i]);
        }
    }
    else {
        recursiveClear(root);
    }
}

void stack::recursiveClear(AST* token) {
    if (token == nullptr){
        return;
    }
    node* a = dynamic_cast<node*>(token);
    recursiveClear(a->left);
    recursiveClear(a->right);
    delete a;
}

void stack::print(){
    for (int i = 0; i < count; i++){
        print1(rpn[i]);
        std::cout << " | ";
    }
}

void stack::print1(AST* token){
    if (token == nullptr){
        return;
    }

    node* a = dynamic_cast<node*>(token);
    print1(a->left);
    std::cout << a->data << " ";
    print1(a->right);
}

void stack::pushNeg(node* token){
    token->left = rpn[count - 1];
    rpn[count - 1] = token;
}

void stack::pushOpp(node* token){
    token->left = rpn[count - 2];
    token->right = rpn[count - 1];
    rpn[count - 2] = token;
    rpn[count - 1] = nullptr;
    count--;
}

void stack::push(node* token){
    rpn[count] = token;
    count++;
}

AST* stack::pop(){
    count--;
    rpn[count] = nullptr;
    return root;
}