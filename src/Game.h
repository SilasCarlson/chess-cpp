#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"

class Game {
    public:
        Game();
        void run();

    private:
        bool m_is_running;
        bool m_is_white_turn = true;
        Board m_board;
};


#endif //CHESS_GAME_H