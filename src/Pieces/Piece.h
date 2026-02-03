#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class Board;

class Piece {
    public:
        Piece(int x, int y, bool is_white_piece, char symbol);
        char get_symbol() const;
        int get_x() const;
        int get_y() const;
        bool is_white_piece() const;
        virtual bool is_legal_move(int x, int y, Board const &board) = 0;

    private:
        int m_x, m_y;
        bool m_is_white_piece;
        char m_symbol;
};


#endif