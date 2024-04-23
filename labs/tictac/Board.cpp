#include "Errors.h"
#include "Board.h"
#include <iostream>
#include <cctype>

// Space for implementing Board functions.

void Board::input_move(Move move){
    int num = move.number;
    char player = toupper(move.player);
    char row = toupper(move.row);
    int column = move.column - 1;

    try { // incorrect move numbering
        if (turn != num){
            InvalidMove error("Invalid move.");
            throw error;
        }
    }
    catch (const InvalidMove& e){
        std::cout << e.what() << std::endl;
        exit(2);
    }

    try { // incorrect player order
        if (prevTurn == player){
            InvalidMove error("Invalid move.");
            throw error;
        }
    }
    catch (const InvalidMove& e){
        std::cout << e.what() << std::endl;
        exit(2);
    }


    try {
        if (gameOver){
            InvalidMove error("Invalid move.");
            throw error;
        }
    }
    catch (InvalidMove& e){
        std::cout << e.what() << std::endl;
        exit(2);
    }
    if (row == 'A'){
        try {
            if (rowA[column] == 'N'){
                rowA[column] = player;
            }
            else {
                std::cout << rowA[column];
                InvalidMove error("Invalid move.");
                throw error;
            }
        }
        catch (InvalidMove& e){
            std::cout << e.what() << std::endl;
            exit(2);
        }
    }
    else if (row == 'B'){
        try {
            if (rowB[column] == 'N'){
                rowB[column] = player;
            }
            else {
                InvalidMove error("Invalid move.");
                throw error;
            }
        }
        catch (InvalidMove& e){
            std::cout << e.what() << std::endl;
            exit(2);
        }
    }
    else if (row == 'C'){
        try {
            if (rowC[column] == 'N'){
                rowC[column] = player;
            }
            else {
                InvalidMove error("Invalid move.");
                throw error;
            }
        }
        catch (InvalidMove& e){
            std::cout << e.what() << std::endl;
            exit(2);
        }
    }

    prevTurn = player;
    turn += 1;
    test_status();
}


bool Board::test_status(){
    if (rowA[0] == rowA[1] && rowA[1] == rowA[2] && rowA[0] != 'N'){
        gameOver = true;
    }
    else if (rowB[0] == rowB[1] && rowB[1] == rowB[2] && rowB[0] != 'N'){
        gameOver = true;
    }
    else if (rowC[0] == rowC[1] && rowC[1] == rowC[2] && rowC[0] != 'N'){
        gameOver = true;
    }
    else if (rowA[0] == rowB[0] && rowB[0] == rowC[0] && rowA[0] != 'N'){
        gameOver = true;
    }
    else if (rowA[1] == rowB[1] && rowB[1] == rowC[1] && rowA[1] != 'N'){
        gameOver = true;
    }
    else if (rowA[2] == rowB[2] && rowB[2] == rowC[2] && rowA[2] != 'N'){
        gameOver = true;
    }
    else if (rowA[0] == rowB[1] && rowB[1] == rowC[2] && rowA[0] != 'N'){
        gameOver = true;
    }
    else if (rowA[2] == rowB[1] && rowB[1] == rowC[0] && rowA[2] != 'N'){
        gameOver = true;
    }
    
    return gameOver;
}

std::string Board::game_status(){
    if (test_status()){
        std::string text = "Game over: ";
        text += prevTurn;
        return text + " wins.";
    }
    else if (!(test_status()) && turn == 10){
        return "Game over: Draw.";
    }
    else if (turn == 1){
        return "Game in progress: New game.";
    }
    else {
        std::string text = "Game in progress: ";
        if (prevTurn == 'X'){
            text += 'O';
        }
        else {
            text += 'X';
        }
        return text + "\'s turn.";
    }
}

void Board::end(){
    if (!(extra)){
        std::cout << game_status() << std::endl;
        extra = true;
        return;
    }

    try {
        if (extra){
            InvalidMove error("Invalid move.");
            throw error;
        }
    }
    catch (InvalidMove& e){
        std::cout << e.what() << std::endl;
        exit(2);
    }
}