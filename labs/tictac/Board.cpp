#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.

void Board::input_move(Move move){
    int num = move.number;
    char player = toupper(move.player);
    //char row = toupper(move.row);
    //int column = move.column - 1;


    if (turn == 1){
        prevTurn = player;
    }

    if (turn != num){
        InvalidMove turn("Invalid move.");
        throw turn;
        exit(2);
    }

    if (prevTurn == player && turn != 1){
        InvalidMove turn("Invalid move.");
        throw turn;
        exit(2);
    }

   /*//std::cout << player << row << column << std::endl;
    std::cout << "Endhere";

    if (turn != num){
        InvalidMove turn("Invalid move.");
        throw turn;
        exit(2);
    }

    if (turn == 1){
        prevTurn = player;
    }

    if (player == prevTurn && turn != 1){
        InvalidMove playerturn("Invalid move.");
        throw playerturn;
        exit(2);
    }
    prevTurn = player;

    if (row == 'A'){
        if (rowA[column] == 'X' || rowA[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowA[column] = player;
    }
    else if (row == 'B'){
        if (rowB[column] == 'X' || rowB[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowB[column] = player;
    }
    else if (row == 'C'){
        if (rowC[column] == 'X' || rowC[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowC[column] = player;
    }
    turn += 1;*/
    prevTurn = player;
    turn += 1;
}

bool Board::test_horizontal() const{
    if (rowA[0] == rowA[1] && rowA[1] == rowA[2]){
        return true;
    }
    else if (rowB[0] == rowB[1] && rowB[1] == rowB[2]){
        return true;
    }
    else if (rowC[0] == rowC[1] && rowC[1] == rowC[2]){
        return true;
    }
    
    return false;
}

bool Board::test_vertical() const{
    if (rowA[0] == rowB[0] && rowB[0] == rowC[0]){
        return true;
    }
    else if (rowA[1] == rowB[1] && rowB[1] == rowC[1]){
        return true;
    }
    else if (rowA[2] == rowB[2] && rowB[2] == rowC[2]){
        return true;
    }
    
    return false;
}

bool Board::test_diagonal() const{
    if (rowA[0] == rowB[1] && rowB[1] == rowC[2]){
        return true;
    }
    else if (rowA[2] == rowB[1] && rowB[1] == rowC[0]){
        return true;
    }
    
    return false;
}