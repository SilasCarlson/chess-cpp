#include "BoardSquare.h"

#include <iostream>

BoardSquare::BoardSquare() {
    m_x = 0;
    m_y = 0;
    m_piece = nullptr;
}

BoardSquare::BoardSquare(int x, int y, Piece* piece) {
    m_x = x;
    m_y = y;
    m_piece = piece;
}

void BoardSquare::set_piece(Piece* piece) {
    m_piece = piece;
}

void BoardSquare::draw() const {
    if (m_piece == nullptr) {
        std::cout << "| |";
    } else {
        std::cout << "|" << m_piece->get_symbol() << "|";
    }
}