#include "AST.h"
#include "Nodes.h"
#include "Stack.h"

#include <iostream>
#include <sstream>
#include <cctype>

AST* AST::parse(const std::string& expression) {
    std::string token;
    std::istringstream stream(expression);
    stack currstack;

    while(stream >> token){
        char* end;
        strtod(token.c_str(), &end);
        if (!(end == token.c_str() || *end != '\0')){
            node* a = new node(token, "num");
            currstack.push(a);
        }
        else if (token.length() == 1 && token == "~"){
            node* a = new node(token, "neg");
            currstack.pushNeg(a);
        }
        else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")){
            node* a = new node(token, "opp");
            currstack.pushOpp(a);
        }
        else {
            throw std::runtime_error("Invalid token: " + token);
        }
        currstack.print();
        std::cout << std::endl;
    }
    return currstack.rpn[0];
}