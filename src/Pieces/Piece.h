#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <vector>

class Board;

class Piece {
    public:
        // constructors/destructors
        Piece(int x, int y, bool is_white_piece, char symbol);
        virtual ~Piece() = default;

        // misc
        virtual bool can_move_to(int x, int y, Board &board) const = 0;

        // setters
        void set_position(int x, int y);
        void increment_moves();

        // getters
        [[nodiscard]] char get_symbol() const;
        [[nodiscard]] char get_base_symbol() const;
        [[nodiscard]] int get_x() const;
        [[nodiscard]] int get_y() const;
        [[nodiscard]] bool is_white_piece() const;
        [[nodiscard]] bool has_moved() const;
        [[nodiscard]] std::vector<std::pair<int, int>> get_all_possible_move_destinations(Board &board) const;
        [[nodiscard]] int get_moves() const;

    private:
        char m_symbol;
        int m_x, m_y;
        int m_moves = 0;
        bool m_is_white_piece;
        bool m_has_moved = false;
};


#endif