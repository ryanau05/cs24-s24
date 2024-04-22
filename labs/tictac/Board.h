#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board{
    private:
        char rowA[3];
        char rowB[3];
        char rowC[3];
        int turn = 1;
        char prevTurn;

    public: 
        void input_move(Move move);
        std::string game_status() const;
        bool test_horizontal() const;
        bool test_vertical() const;
        bool test_diagonal() const;
        void turn_order();
};

#endif