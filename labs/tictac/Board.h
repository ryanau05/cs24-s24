#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board{
    private:
        Move rowA[3];
        Move rowB[3];
        Move rowC[3];
        int turn;
        bool isXTurn;

    public: 
        void input_move(Move move);
        std::string game_status() const;
        bool test_horizontal() const;
        bool test_vertical() const;
        bool test_diagonal() const;

        void test_input() const;
};

#endif