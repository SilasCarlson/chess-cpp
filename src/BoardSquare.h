#ifndef CHESS_BOARDSQUARE_H
#define CHESS_BOARDSQUARE_H

#include "Pieces/Piece.h"

class BoardSquare {
    public:
        // constructors/destructors
        BoardSquare();
        BoardSquare(int x, int y, Piece* piece = nullptr);

        // misc
        void draw() const;

        // setters
        void set_piece(Piece* piece);

        // getters
        [[nodiscard]] Piece* get_piece() const;
        [[nodiscard]] bool is_empty() const;
        [[nodiscard]] int get_x() const;
        [[nodiscard]] int get_y() const;

    private:
        int m_x, m_y;
        Piece* m_piece;
};


#endif