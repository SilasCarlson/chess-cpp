#include "Board.h"
#include "Pieces/Pawn.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

#include <iostream>

Board::Board() {
    // initialize the board square
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            m_board_squares[y][x] = BoardSquare(x, y);
        }
    }

    // reserve space for the vector
    m_pieces.reserve(32);

    // Initialize Pieces
    // Pawns
    for (int i = 0; i < 8; i++) {
        // black
        m_pieces.emplace_back(Pawn(i, 1, false));
        set_board_square_piece(i, 1, &m_pieces.back());

        // white
        m_pieces.emplace_back(Pawn(i, 6, true));
        set_board_square_piece(i, 6, &m_pieces.back());
    }

    // rooks
    m_pieces.emplace_back(Rook(0, 0, false));
    set_board_square_piece(0, 0, &m_pieces.back());

    m_pieces.emplace_back(Rook(7, 0, false));
    set_board_square_piece(7, 0, &m_pieces.back());

    m_pieces.emplace_back(Rook(0, 7, true));
    set_board_square_piece(0, 7, &m_pieces.back());

    m_pieces.emplace_back(Rook(7, 7, true));
    set_board_square_piece(7, 7, &m_pieces.back());

    // knights
    m_pieces.emplace_back(Knight(1, 0, false));
    set_board_square_piece(1, 0, &m_pieces.back());

    m_pieces.emplace_back(Knight(6, 0, false));
    set_board_square_piece(6, 0, &m_pieces.back());

    m_pieces.emplace_back(Knight(1, 7, true));
    set_board_square_piece(1, 7, &m_pieces.back());

    m_pieces.emplace_back(Knight(6, 7, true));
    set_board_square_piece(6, 7, &m_pieces.back());

    // bishops
    m_pieces.emplace_back(Bishop(2, 0, false));
    set_board_square_piece(2, 0, &m_pieces.back());

    m_pieces.emplace_back(Bishop(5, 0, false));
    set_board_square_piece(5, 0, &m_pieces.back());

    m_pieces.emplace_back(Bishop(2, 7, true));
    set_board_square_piece(2, 7, &m_pieces.back());

    m_pieces.emplace_back(Bishop(5, 7, true));
    set_board_square_piece(5, 7, &m_pieces.back());

    // queens
    m_pieces.emplace_back(Queen(3, 0, false));
    set_board_square_piece(3, 0, &m_pieces.back());

    m_pieces.emplace_back(Queen(3, 7, true));
    set_board_square_piece(3, 7, &m_pieces.back());

    // kings
    m_pieces.emplace_back(King(3, 0, false));
    set_board_square_piece(4, 0, &m_pieces.back());

    m_pieces.emplace_back(King(3, 7, true));
    set_board_square_piece(4, 7, &m_pieces.back());
}

void Board::set_board_square_piece(int x, int y, Piece* piece) {
    m_board_squares[y][x].set_piece(piece);
}

void Board::draw() {
    std::cout << "   0  1  2  3  4  5  6  7" << std::endl;
    for (int y = 0; y < 8; y++) {
        std::cout << "  +-++-++-++-++-++-++-++-+" << std::endl;
        std::cout << y << " ";
        for (int x = 0; x < 8; x++) {
            m_board_squares[y][x].draw();
        }
        std::cout << std::endl;
    }
    std::cout << "  +-++-++-++-++-++-++-++-+" << std::endl;
}

int Board::get_width() {
    return m_width;
}

int Board::get_height() {
    return m_height;
}