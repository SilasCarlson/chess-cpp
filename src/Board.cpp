#include "Board.h"
#include "Pieces/Piece.h"
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
        m_pieces.push_back(std::make_unique<Pawn>(i, 1, false));
        set_board_square_piece(i, 1, m_pieces.back().get());

        // white
        m_pieces.push_back(std::make_unique<Pawn>(i, 6, true));
        set_board_square_piece(i, 6, m_pieces.back().get());
    }

    // rooks
    m_pieces.push_back(std::make_unique<Rook>(0, 0, false));
    set_board_square_piece(0, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Rook>(7, 0, false));
    set_board_square_piece(7, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Rook>(0, 7, true));
    set_board_square_piece(0, 7, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Rook>(7, 7, true));
    set_board_square_piece(7, 7, m_pieces.back().get());

    // knights
    m_pieces.push_back(std::make_unique<Knight>(1, 0, false));
    set_board_square_piece(1, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Knight>(6, 0, false));
    set_board_square_piece(6, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Knight>(1, 7, true));
    set_board_square_piece(1, 7, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Knight>(6, 7, true));
    set_board_square_piece(6, 7, m_pieces.back().get());

    // bishops
    m_pieces.push_back(std::make_unique<Bishop>(2, 0, false));
    set_board_square_piece(2, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Bishop>(5, 0, false));
    set_board_square_piece(5, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Bishop>(2, 7, true));
    set_board_square_piece(2, 7, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Bishop>(5, 7, true));
    set_board_square_piece(5, 7, m_pieces.back().get());

    // queens
    m_pieces.push_back(std::make_unique<Queen>(3, 0, false));
    set_board_square_piece(3, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<Queen>(3, 7, true));
    set_board_square_piece(3, 7, m_pieces.back().get());

    // kings
    m_pieces.push_back(std::make_unique<King>(4, 0, false));
    set_board_square_piece(4, 0, m_pieces.back().get());

    m_pieces.push_back(std::make_unique<King>(4, 7, true));
    set_board_square_piece(4, 7, m_pieces.back().get());
}

void Board::set_board_square_piece(int x, int y, Piece* piece) {
    m_board_squares[y][x].set_piece(piece);
}

bool Board::is_white_piece(int const x, int const y) const {
    Piece* piece = m_board_squares[y][x].get_piece();

    if (piece != nullptr) {
        return piece->is_white_piece();
    }

    return false;
}

bool Board::move_piece(int const initial_x, int const initial_y, int const final_x, int const final_y) {
    // steps
    // 1. grab corresponding piece
    // 2. ensure it exists
    // 3. make sure this is a valid move
    // 4. if there is a piece on the destination then destroy it
    // 5. update the initial position's piece
    // 6. update the final position's piece
    Piece* piece = m_board_squares[initial_y][initial_x].get_piece();

    if (piece != nullptr) {
        if (piece->is_legal_move(final_x, final_y, *this)) {
            // delete the piece on the destination square (if it exists)
            Piece* piece_destination = m_board_squares[final_y][final_x].get_piece();
            delete piece_destination; // delete this from memory

            m_board_squares[initial_y][initial_x].set_piece(nullptr);
            m_board_squares[final_y][final_x].set_piece(piece);

            return true;
        }
    }

    return false;
}

void Board::draw() {
    std::cout << "   a  b  c  d  e  f  g  h" << std::endl;
    for (int y = 0; y < 8; y++) {
        std::cout << "  +-++-++-++-++-++-++-++-+" << std::endl;
        std::cout << 8 - y << " ";
        for (int x = 0; x < 8; x++) {
            m_board_squares[y][x].draw();
        }
        std::cout << std::endl;
    }
    std::cout << "  +-++-++-++-++-++-++-++-+" << std::endl;
    std::cout << "   a  b  c  d  e  f  g  h" << std::endl;
}