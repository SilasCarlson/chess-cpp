#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
    public:
        Knight(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'N') {};
        bool is_legal_move(int x, int y, Board const &board);
};


#endif