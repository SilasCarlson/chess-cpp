#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"

class Queen : public Piece {
    public:
        Queen(int x, int y, bool is_white_piece) : Piece(x, y, is_white_piece, 'Q') {};
        bool is_legal_move(int x, int y, Board const &board);
};


#endif