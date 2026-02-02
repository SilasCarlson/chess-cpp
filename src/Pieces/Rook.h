#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece {
    public:
        Rook(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'R') {};
};


#endif