#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <string>

int main() {
    std::string text;

    std::getline(std::cin, text);
    
    Move move(text);

    std::string a = move.to_string();

    std::cout << a;
    

    return 0;
}
