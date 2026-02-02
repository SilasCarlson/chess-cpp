#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include "Pieces/Piece.h"
#include "BoardSquare.h"

class Board {
    public:
        Board();
        int get_width();
        int get_height();
        void draw();

    private:
        BoardSquare m_board_squares[8][8];
        std::vector<Piece> m_pieces;
        int m_width = 8;
        int m_height = 8;
        void set_board_square_piece(int x, int y, Piece* piece);

};


#endif