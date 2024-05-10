#include "Stack.h"
#include "Nodes.h"
#include <iostream>

// Implement your Stack member functions here.
// stack::stack(){
//     count = 0;
// }

// stack::~stack(){
//     if (count > 0){
//         for (int i = 0; i < count; i++){
//             recursiveClear(rpn[i]);
//         }
//     }
//     else {
//         recursiveClear(root);
//     }
// }

// void stack::recursiveClear(AST* token) {
//     if (token == nullptr){
//         return;
//     }
//     node* a = dynamic_cast<node*>(token);
//     recursiveClear(a->left);
//     recursiveClear(a->right);
//     delete a;
// }

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

// std::string stack::PN(AST* token) const{
//     if (token == nullptr){
//         return "";
//     }

//     node* a = dynamic_cast<node*>(token);
//     std::string x = "";
//     print1(a->left);
//     print1(a->right);
//     x += a->data + " ";
//     return x;
// }

// void stack::pushNeg(node* token){
//     token->left = rpn[count - 1];
//     rpn[count - 1] = token;
// }

// void stack::pushOpp(node* token){
//     token->left = rpn[count - 2];
//     token->right = rpn[count - 1];
//     rpn[count - 2] = token;
//     rpn[count - 1] = nullptr;
//     count--;
// }

// void stack::push(node* token){
//     rpn[count] = token;
//     count++;
// }

// AST* stack::pop(){
//     count--;
//     rpn[count] = nullptr;
//     return root;
// }




stack::stack(){
    top = -1;
}

stack::~stack(){
    for (int i = top; i >= 0; i--){
        recursiveClear(rpn[i]);
        pop();
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

void stack::pushNum(node* token){
    rpn[++top] = token;
}

void stack::pushNeg(node* token){
    token->left = topNode();
    pop();
    rpn[++top] = token;
}

void stack::pushOpp(node* token){
    token->right = topNode();
    pop();
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