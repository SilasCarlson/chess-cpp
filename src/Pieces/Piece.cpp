#include "Piece.h"

#include <iostream>

Piece::Piece(int x, int y, bool is_white_piece, char symbol) {
    m_x = x;
    m_y = y;
    m_is_white_piece = is_white_piece;
    m_symbol = symbol;
}

char Piece::get_symbol() const {
    if (!m_is_white_piece) return static_cast<char>(std::tolower(m_symbol));

    return m_symbol;
}

int Piece::get_x() const {
    return m_x;
}

int Piece::get_y() const {
    return m_y;
}