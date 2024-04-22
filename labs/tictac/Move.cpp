#include "Errors.h"
#include "Move.h"
#include <string>
#include <cctype>
#include <iostream>

// Space for implementing Move functions.

Move::Move(const std::string& input){
    if (input.length() < 6){
        ParseError format("Parse error.");
        exit(1);
    }

    number = input[0] - '0';
    if (!(number >= 1 && number <= 9)){
        ParseError num("Parse error.");
        exit(1);
    }

    if (!(isspace(input[1])) || !(isspace(input[3]))){
        ParseError whitespace("Parse error.");
        exit(1);
    }

    player = input[2];
    if (player != 'X' && player != 'O'){
        ParseError player("Parse error.");
        exit(1);
    }

    row = input[4];
    if (!((row >= 65 && row <= 67) || (row >= 97 && row <= 99))){
        ParseError row("Parse error.");
        exit(1);
    }


    column = input[5] - '0';
    if (!(column >= 1 && column <= 3)){
        ParseError column("Parse error.");
        exit(1);
    }

    int size = input.length();
    for (int i = 6; i < size; i++){
        if (input[i] != '#' || input[i - 1] != ' '){
            ParseError comment("Parse error.");
            exit(1);
        }
    }

    std::cout << to_string();
    exit(0);
}

std::string Move::to_string() const{
    std::string move = std::to_string(number) + ' ' + player + ' ' + (char)row + std::to_string(column);
    return move;
}