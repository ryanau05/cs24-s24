#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.

void Board::input_move(Move move){
    int num = move.number;
    char player = toupper(move.player);
    char row = toupper(move.row);
    int column = move.column - 1;

    //std::cout << player << row << column << std::endl;

    if (turn != num - 1){
        InvalidMove turn("Invalid move.");
        throw turn;
        exit(2);
    }
    turn += 1;
    if (turn == 1){
        prevTurn = player;
    }

    if (player == prevTurn && turn != 1){
        InvalidMove playerturn("Invalid move.");
        throw playerturn;
        exit(2);
    }

    if (row == 'A'){
        if (rowA[column] == 'X' && rowA[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowA[column] = player;
    }
    else if (row == 'B'){
        if (rowB[column] == 'X' && rowB[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowB[column] = player;
    }
    else if (row == 'C'){
        if (rowC[column] == 'X' && rowC[column] == 'O'){
            InvalidMove taken("Invalid move.");
            throw taken;
            exit(2);
        }
        rowC[column] = player;
    }
    prevTurn = player;
}