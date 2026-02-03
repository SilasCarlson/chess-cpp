#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
    public:
        Bishop(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'B') {};
        bool is_legal_move(int x, int y, Board const &board);
};


#endif