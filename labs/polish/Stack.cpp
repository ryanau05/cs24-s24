#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// Implement your Stack member functions here.
void stack::print() const{
    for (int i = 0; i <= top; i++){
        print1(rpn[i]);
        std::cout << " | ";
    }
}

void stack::print1(AST* token) const{
    if (token == nullptr){
        return;
    }

    node* a = dynamic_cast<node*>(token);
    print1(a->left);
    print1(a->right);
    std::cout << a->data << " ";
}

stack::stack(){
    top = -1;
}

stack::~stack(){
    clear();
}

void stack::clear(){
    for (int i = top; i >= 0; i--){
        recursiveClear(rpn[i]);
    }
    clearStack();
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

void stack::clearStack(){
    for (int i = top; i >= 0; i--){
        delete rpn[i];
    }
    top = -1;
}

void stack::pushNum(node* token){
    rpn[++top] = token;
}

void stack::pushNeg(node* token){
    if (topNode() == nullptr){
        clear();
        throw std::runtime_error("Not enough operands.");
    }
    token->left = topNode();
    pop();
    rpn[++top] = token;
}

void stack::pushOpp(node* token){
    if (topNode() == nullptr){
        clear();
        throw std::runtime_error("Not enough operands.");
    }
    token->right = topNode();
    pop();
    if (topNode() == nullptr){
        clear();
        throw std::runtime_error("Not enough operands.");
    }
    token->left = topNode();
    pop();
    rpn[++top] = token;
}

void stack::pop(){
    if (top == -1){
        return;
    }
    rpn[top--] = nullptr;
}

AST* stack::topNode(){
    if (top == -1){
        return nullptr;
    }

    return rpn[top];
}

bool stack::isEmpty(){
    if (top == -1){
        return true;
    }
    else {
        return false;
    }
}