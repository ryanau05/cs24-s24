#include "Errors.h"
#include "Move.h"
#include <string>
#include <cctype>
#include <iostream>

// Space for implementing Move functions.

Move::Move(const std::string& input){
    int length = input.length();
    int num = 0;
    for (int i = 0; i < length; i++){
        if (isalnum(input[i])){
            num++;
        }
    }

    if (num < 4){
        //std::cout << "Parse error." << std::endl;
        ParseError size("Parse error.");
        throw size;
        exit(1);
    }

    int i = 0;
    int count = 0;

    while (i < length){
        if (!(isspace(input[i]))){
            if (count == 0){
                if (!(input[i] - '0' >= 1 && input[i] - '0' <= 9) || isspace(input[i - 1])){
                    //std::cout << "Parse error." << std::endl;
                    ParseError number("Parse error");
                    throw number;
                    exit(1);
                }
                else {
                    number = input[i] - '0';
                    count++;
                }
            }
            else if (count == 1){
                if ((input[i] != 'X' && input[i] != 'x' && input[i] != 'O' && input[i] != 'o') || !(isspace(input[i - 1]))){
                    //std::cout << "Parse error." << std::endl;
                    ParseError player("Parse error");
                    throw player;
                    exit(1);
                }
                else {
                    player = input[i];
                    count++;
                }
            }
            else if (count == 2){
                if (!((input[i] >= 65 && input[i] <= 67) || (input[i] >= 97 && input[i] <= 99)) || !(isspace(input[i - 1]))){
                    //std::cout << "Parse error." << std::endl;
                    ParseError row("Parse error");
                    throw row;
                    exit(1);
                }
                else {
                    row = input[i];
                    count++;
                }
            }
            else if (count == 3){
                if (!(input[i] - '0' >= 1 && input[i] - '0' <= 3) || (input[i - 1] != row)){
                    //std::cout << "Parse error." << std::endl;
                    ParseError column("Parse error");
                    throw column;
                    exit(1);
                }
                else {
                    column = input[i] - '0';
                    count++;
                }
            }
            else if (count == 4){
                if (!(input[i] == '#' && isspace(input[i - 1]))){
                    //std::cout << "Parse error." << std::endl;
                    ParseError comment("Parse error");
                    throw comment;
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