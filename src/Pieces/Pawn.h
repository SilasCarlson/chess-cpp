#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece {
    public:
        Pawn(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'P') {};
        bool can_move_to(int x, int y, Board &board) const override;
};


#endif