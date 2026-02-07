#include "Piece.h"

#include <iostream>

#include "../Board.h"

Piece::Piece(const int x, const int y, const bool is_white_piece, const char symbol) {
    m_x = x;
    m_y = y;
    m_is_white_piece = is_white_piece;
    m_symbol = symbol;
}

void Piece::set_position(const int x, const int y) {
    m_x = x;
    m_y = y;
    m_has_moved = true;
}

void Piece::increment_moves() {
    m_moves++;
}

char Piece::get_symbol() const {
    if (!m_is_white_piece) return static_cast<char>(std::tolower(m_symbol));

    return m_symbol;
}

char Piece::get_base_symbol() const {
    return m_symbol;
}

int Piece::get_x() const {
    return m_x;
}

int Piece::get_y() const {
    return m_y;
}

bool Piece::is_white_piece() const {
    return m_is_white_piece;
}

bool Piece::has_moved() const {
    return m_has_moved;
}

std::vector<std::pair<int, int>> Piece::get_all_possible_move_destinations(Board &board) const {
    std::vector<std::pair<int, int>> legal_moves;

    // go through every position on the board and if this piece can move there
    // then add that board square's coordinates to the return set
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (can_move_to(x, y, board) && (board.get_board_square(x, y).get_piece() == nullptr || board.get_board_square(x, y).get_piece()->is_white_piece() != is_white_piece())) {
                legal_moves.emplace_back(x, y);
            }
        }
    }

    return legal_moves;
}

int Piece::get_moves() const {
    return m_moves;
}