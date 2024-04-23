#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board{
    private:
        char rowA[3] = {'N','N','N'};
        char rowB[3] = {'N','N','N'};
        char rowC[3] = {'N','N','N'};
        int turn = 1;
        char prevTurn = 'N';

    public: 
        void input_move(Move move);
        std::string game_status();
        bool test_status();
        void turn_order();
       // void end();
        bool gameOver = false;
        //bool extra = false;
};

#endif