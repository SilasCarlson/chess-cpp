#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
    public:
        Pawn(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'P') {};
        bool is_legal_move(int x, int y, Board const &board);
};


#endif