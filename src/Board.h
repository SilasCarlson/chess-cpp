#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>
#include <vector>
#include "BoardSquare.h"

class Piece;

class Board {
    public:
        Board();
        void draw() const;
        bool move_piece(int initial_x, int initial_y, int final_x, int final_y);
        bool is_white_piece(int x, int y) const;
        BoardSquare get_board_square(int x, int y) const;
        bool king_is_in_checkmate(bool is_white_piece) const;

    private:
        BoardSquare m_board_squares[8][8];
        std::vector<std::unique_ptr<Piece>> m_pieces;
        int m_width = 8;
        int m_height = 8;
        void set_board_square_piece(int x, int y, Piece* piece);
        bool king_is_in_check(bool is_white_piece) const;

};


#endif