#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"

class Game {
    public:
        // constructor/destructor
        Game();

        // misc
        void start();

    private:
        // attributes/props
        bool m_is_running;
        bool m_is_white_turn = true;
        Board m_board;

        // methods
        [[nodiscard]] static int get_position_from_letter(char letter);
        void run();
};


#endif //CHESS_GAME_H