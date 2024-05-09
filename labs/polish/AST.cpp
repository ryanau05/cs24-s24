#include "AST.h"
#include "Nodes.h"
#include "Stack.h"

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
            currstack.push(new num(stod(token)));
        }
        else if (token.length() == 1 && token == "~"){
            currstack.push(new neg);
        }
        else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")){
            currstack.push(new opp(token[0]));
        }
        else {
            throw std::runtime_error("Invalid token: " + token);
        }

    }

    return currstack.rpn[0];
}
