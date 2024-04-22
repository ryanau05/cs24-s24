#include "Errors.h"
#include "Move.h"

// Space for implementing Move functions.

Move::Move(const std::string& input){
    if (input.length() < 6){
        ParseError format("Invalid Format");
        exit(1);
    }

    number = input[0] - '0';
    if (!(number >= 1 && number <= 9)){
        ParseError num("Invalid Number");
        exit(1);
    }

    if (input[1] != ' ' && input[3] != ' '){
        ParseError whitespace("Invalid Spacing");
        exit(1);
    }

    player = input[2];
    if (player != 'X' && player != 'O'){
        ParseError player("Invalid Player");
        exit(1);
    }

    row = input[4];
    if (!(row >= 65 && row <= 67)){
        ParseError row("Invalid Row");
        exit(1);
    }

    column = input[5];
    if (!(column >= 1 && column <= 3)){
        ParseError column("Invalid Column");
        exit(1);
    }

}