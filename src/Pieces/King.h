#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {
    public:
        King(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'K') {};
        bool is_legal_move(int x, int y, const Board &board) const override;
};


#endif //CHESS_KING_H