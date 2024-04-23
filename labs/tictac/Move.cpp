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

    try {
        if (num < 4){
            //std::cout << "Parse error." << std::endl;
            ParseError size("Parse error.");
            throw size;
            exit(1);
        }
    }
    catch (const ParseError& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }

    int i = 0;
    int count = 0;
    try {
        if (!(isdigit(input[0]))){
            ParseError error("Parse error.");
            throw error;
            exit(1);
        }
    }
    catch (const ParseError& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }

    while (i < length){
        if (!(isspace(input[i]))){
            if (count == 0){
                try {
                    if (!(input[i] - '0' >= 1 && input[i] - '0' <= 9)){
                        ParseError error("Parse error.");
                        throw error;
                    }
                    else {
                        number = input[i] - '0';
                        count++;
                    }
                }
                catch (const ParseError& e) {
                    std::cout << e.what() << std::endl;
                    exit(1);
                }
            }
            else if (count == 1){
                try {
                    if ((input[i] != 'X' && input[i] != 'x' && input[i] != 'O' && input[i] != 'o') || !(isspace(input[i - 1]))){
                        ParseError error("Parse error.");
                        throw error;
                    }
                    else {
                        player = input[i];
                        count++;
                    }
                }
                catch (const ParseError& e) {
                    std::cout << e.what() << std::endl;
                    exit(1);
                }
            }
            else if (count == 2){
                try {
                    if (!((input[i] >= 65 && input[i] <= 67) || (input[i] >= 97 && input[i] <= 99)) || !(isspace(input[i - 1]))){
                        ParseError error("Parse error.");
                        throw error;
                    }
                    else {
                        row = input[i];
                        count++;
                    }
                }
                catch (const ParseError& e) {
                    std::cout << e.what() << std::endl;
                    exit(1);
                }
            }
            else if (count == 3){
                try {
                    if (!(input[i] - '0' >= 1 && input[i] - '0' <= 3) || (input[i - 1] != row)){
                        ParseError error("Parse error.");
                        throw error;
                    }
                    else {
                        column = input[i] - '0';
                        count++;
                    }
                }
                catch (const ParseError& e) {
                    std::cout << e.what() << std::endl;
                    exit(1);
                }
            }
            else if (count == 4){
                try {
                    if (!(input[i] == '#' && isspace(input[i - 1]))){
                        ParseError error("Parse error.");
                        throw error;
                    }
                    else {
                        break;
                    }
                }
                catch (const ParseError& e) {
                    std::cout << e.what() << std::endl;
                    exit(1);
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