#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
#include <string>

int main() {
    //bool verbose = false;
    std::string text;
    Board test;
    while(std::getline(std::cin, text)){
        Move move(text);
        test.input_move(move);
    }

    return 0;
}
