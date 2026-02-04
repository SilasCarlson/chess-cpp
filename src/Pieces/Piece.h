#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <vector>

class Board;

class Piece {
    public:
        Piece(int x, int y, bool is_white_piece, char symbol);
        char get_symbol() const;
        int get_x() const;
        int get_y() const;
        bool is_white_piece() const;
        bool has_moved() const;
        void set_position(int x, int y);
        virtual bool is_legal_move(int x, int y, const Board &board) const = 0;
        std::vector<std::pair<int, int>> get_legal_moves(const Board &board) const;

    private:
        int m_x, m_y;
        bool m_is_white_piece;
        char m_symbol;
        bool m_has_moved = false;
};


#endif