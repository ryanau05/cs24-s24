#include "Errors.h"
#include "Move.h"
#include <string>
#include <cctype>

// Space for implementing Move functions.

Move::Move(const std::string& input){
    if (input.length() < 6){
        ParseError format("Invalid Format");
        exit(0);
    }

    number = input[0] - '0';
    if (!(number >= 1 && number <= 9)){
        ParseError num("Invalid Number");
        exit(0);
    }

    if (input[1] != ' ' && input[3] != ' '){
        ParseError whitespace("Invalid Spacing");
        exit(0);
    }

    player = input[2];
    if (player != 'X' && player != 'O'){
        ParseError player("Invalid Player");
        exit(0);
    }

    row = input[4];
    if (!((row >= 65 && row <= 67) || (row >= 97 && row <= 99))){
        ParseError row("Invalid Row");
        exit(0);
    }

    column = input[5];
    if (!(column >= 1 && column <= 3)){
        ParseError column("Invalid Column");
        exit(0);
    }

    int size = input.length();
    for (int i = 6; i < size; i++){
        if (!(isspace(input[i])) && input[i - 2] != '#' && input[i - 3] != ' '){
            ParseError comment("Invalid Format");
            exit(0);
        }
    }
}

std::string Move::to_string() const{
    std::string move = std::to_string(number) + ' ' + player + ' ' + (char)row + std::to_string(column);
    return move;
}