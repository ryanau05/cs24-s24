#include "Errors.h"
#include "Move.h"
#include <string>
#include <cctype>
#include <iostream>

// Space for implementing Move functions.

Move::Move(const std::string& input){
    /*if (input.length() < 6){
        ParseError format("Parse error.");
        exit(0);
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
    if (player != 'X' && player != 'O' && input[2] != 'x' && input[2] != 'o'){
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
    }*/

    /*int size = input.length();
    for (int i = 6; i < size; i++){
        if (input[i] != '#' || !(isspace(input[i - 1]))){
            ParseError comment("Parse error.");
            exit(0);
        }
    }*/

    /*if (input.length() < 6){
        ParseError size("Parse error.");
        exit(1);
    }

    if (!(input[0] >= 1 && input[0] <= 9)){
        ParseError number("Parse error.");
        exit(1);
    }
    int number = input[0];

    if (!(isspace(input[1]) && isspace(input[3]))){
        ParseError whitespace("Parse error.");
        exit(1);
    }

    if (!(input[2] == 'X' || input[2] == 'O' || input[2] == 'x' || input[2] == 'o')){
        ParseError player("Parse error.");
        exit(1);
    }
    char player = input[2];

    if ((input[4] >= 65 && input[4] <= 67) || (input[4] >= 97 && input[4] <= 99)){
        ParseError row("Parse error.");
        exit(1);
    }
    int row = input[4];

    if (!(input[5] - '0' >= 1 && input[5] - '0' <= 3)){
        ParseError column("Parse error.");
        exit(1);
    }

    if (input.length() > 6){

    }*/

    int i = 0;
    int count = 0;
    int length = input.length();
    while (i < length){
        if (!(isspace(input[i]))){
            if (count == 0){
                if (!(input[i] - '0' >= 1 && input[i] - '0' <= 9) || isspace(input[i - 1])){
                    std::cout << "Parse error." << std::endl;
                    exit(1);
                }
                else {
                    number = input[i] - '0';
                    count++;
                }
            }
            else if (count == 1){
                if ((input[i] != 'X' && input[i] != 'x' && input[i] != 'O' && input[i] != 'o') || !(isspace(input[i - 1]))){
                    std::cout << "Parse error." << std::endl;
                    exit(1);
                }
                else {
                    player = input[i];
                    count++;
                }
            }
            else if (count == 2){
                if (!((input[i] >= 65 && input[i] <= 67) || (input[i] >= 97 && input[i] <= 99)) || !(isspace(input[i - 1]))){
                    std::cout << "Parse error." << std::endl;
                    exit(1);
                }
                else {
                    row = input[i];
                    count++;
                }
            }
            else if (count == 3){
                if (!(input[i] - '0' >= 1 && input[i] - '0' <= 3) || (input[i - 1] != row)){
                    std::cout << "Parse error." << std::endl;
                    exit(1);
                }
                else {
                    column = input[i] - '0';
                    count++;
                }
            }
            else if (count == 4){
                if (!(input[i] == '#' && isspace(input[i - 1]))){
                    std::cout << "Parse error." << std::endl;
                    exit(1);
                }
                else {
                    break;
                }
            }
        }
        i++;
    }

}

std::string Move::to_string() const{
    char x = toupper(player);
    char y = toupper(row);
    std::string move = std::to_string(number) + ' ' + x + ' ' + y + std::to_string(column);
    return move;
}