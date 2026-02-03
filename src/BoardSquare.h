#ifndef CHESS_BOARDSQUARE_H
#define CHESS_BOARDSQUARE_H

#include "Pieces/Piece.h"

class BoardSquare {
    public:
        BoardSquare();
        BoardSquare(int x, int y, Piece* piece = nullptr);
        void set_piece(Piece* piece);
        void draw() const;
        Piece* get_piece() const;
        bool is_empty() const;

    private:
        int m_x, m_y;
        Piece* m_piece;
};


#endif