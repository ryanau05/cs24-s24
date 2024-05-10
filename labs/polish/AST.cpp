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
            currstack.pushNum(new node(token, "num"));
        }
        else if (token.length() == 1 && token == "~"){
            currstack.pushNeg(new node(token, "neg"));
        }
        else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")){
            currstack.pushOpp(new node(token, "opp"));
        }
        else {
            currstack.clear();
            throw std::runtime_error("Invalid token: " + token);
        }
        // currstack.print();
        // std::cout << std::endl;
   }
    AST* temp = currstack.topNode();
    currstack.pop();
    return temp;
}