#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {
    public:
        King(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'K') {};
        bool can_move_to(int x, int y, Board &board) const override;
};


#endif //CHESS_KING_H