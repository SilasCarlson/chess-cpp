#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>
#include <optional>
#include <vector>
#include "BoardSquare.h"

class Piece;

class Board {
    public:
        // constructor/destructors
        Board();

        // misc
        void draw() const;
        bool move_piece(int initial_x, int initial_y, int final_x, int final_y);
        void promote_pawn(const Piece* piece);

        // setters
        void set_en_passant_target(int x, int y);

        // getters
        [[nodiscard]] BoardSquare get_board_square(int x, int y) const;
        [[nodiscard]] bool is_white_piece(int x, int y) const;
        [[nodiscard]] bool king_is_in_checkmate(bool is_white_piece);
        [[nodiscard]] Piece* get_last_moved_piece() const;

    private:
        // props/attributes
        BoardSquare m_board_squares[8][8];
        std::vector<std::unique_ptr<Piece>> m_pieces;
        Piece* m_last_moved_piece = nullptr;
        int m_pieces_moved = 0;
        std::optional<std::pair<int, int>> m_en_passant_target = std::nullopt;

        // methods
        void set_board_square_piece(int x, int y, Piece* piece);
        bool king_is_in_check(bool is_white_piece);
};


#endif