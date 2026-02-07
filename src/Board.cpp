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

void Board::draw() const {
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
        if (piece->can_move_to(final_x, final_y, *this)) {
            // delete the piece on the destination square (if it exists)
            Piece* piece_destination = m_board_squares[final_y][final_x].get_piece();

            // prevent the player from taking over their own piece essentially
            if (piece_destination == nullptr || piece->is_white_piece() != piece_destination->is_white_piece()) {
                // move the pieces around
                set_board_square_piece(initial_x, initial_y, nullptr);
                set_board_square_piece(final_x, final_y, piece);
                piece->set_position(final_x, final_y);

                // Ensure that with the new updated position this does
                // not place the King in check
                if (king_is_in_check(piece->is_white_piece())) {
                    // undo the movement
                    set_board_square_piece(initial_x, initial_y, piece);
                    set_board_square_piece(final_x, final_y, piece_destination);
                    piece->set_position(initial_x, initial_y);

                    // exit early
                    return false;
                }

                if (m_en_passant_target != std::nullopt) {
                    m_board_squares[m_en_passant_target->second][m_en_passant_target->first].set_piece(nullptr);
                }

                if (piece->get_base_symbol() == 'P' && (final_y == 0 || final_y == 7)) {
                    promote_pawn(piece);
                }

                piece->increment_moves();
                m_last_moved_piece = piece;
                m_pieces_moved++;
                m_en_passant_target = std::nullopt;

                return true;
            }
        }
    }

    return false;
}

void Board::promote_pawn(const Piece* piece) {
    // get user input
    std::string user_input;
    std::cout << "What will you promote your pawn to?" << std::endl << "1. Rook" << std::endl << "2. Knight" << std::endl << "3. Bishop" << std::endl << "4. Queen" << std::endl;
    std::cin >> user_input;

    // get props from the piece before deleting it
    const int x = piece->get_x();
    const int y = piece->get_y();
    const bool is_white_piece = piece->is_white_piece();

    // we will assume the player will most likely choose a queen (so this is the default if no other choice is chosen)
    switch (std::stoi(user_input)) {
        case 1:
            m_pieces.emplace_back(std::make_unique<Rook>(x, y, is_white_piece));
            break;

        case 2:
            m_pieces.emplace_back(std::make_unique<Knight>(x, y, is_white_piece));
            break;

        case 3:
            m_pieces.emplace_back(std::make_unique<Bishop>(x, y, is_white_piece));
            break;

        default:
            m_pieces.emplace_back(std::make_unique<Queen>(x, y, is_white_piece));
            break;
    }

    m_board_squares[y][x].set_piece(m_pieces.back().get());
}

void Board::set_en_passant_target(const int x, const int y) {
    m_en_passant_target = {x, y};
}

void Board::set_board_square_piece(const int x, const int y, Piece* piece) {
    m_board_squares[y][x].set_piece(piece);
}

BoardSquare Board::get_board_square(const int x, const int y) const {
    return m_board_squares[y][x];
}

bool Board::is_white_piece(int const x, int const y) const {
    Piece* piece = m_board_squares[y][x].get_piece();

    if (piece != nullptr) {
        return piece->is_white_piece();
    }

    return false;
}

bool Board::king_is_in_checkmate(bool is_white_piece) {
    // Get the King piece
    const Piece* king = nullptr;
    const char king_symbol = is_white_piece ? 'K' : 'k';
    for (const std::unique_ptr<Piece> &piece : m_pieces) {
        if (piece->get_symbol() == king_symbol) {
            king = piece.get();
        }
    }

    // Ensure that we don't have a null pointer (even tho this should never really happen)
    // failsafe
    if (king == nullptr) return true;

    // ensure the king is currently in check
    if (!king_is_in_check(is_white_piece)) return false;

    // if king cannot move without being sent into check
    bool king_can_escape = false;
    std::vector<std::pair<int, int>> king_legal_moves = king->get_all_possible_move_destinations(*this);
    for (std::pair<int, int> position : king_legal_moves) {
        bool square_blocked = false;
        for (const std::unique_ptr<Piece> &piece : m_pieces) {
            if (piece->can_move_to(position.first, position.second, *this)) {
                square_blocked = true;
            }
        }

        if (!square_blocked) {
            king_can_escape = true;
        }
    }

    // if the king can escape then he is not currently in checkmate
    if (king_can_escape) return false;

    // if another piece can stop the check
    for (const std::unique_ptr<Piece> &piece : m_pieces) {
        const std::vector<std::pair<int, int>> all_possible_moves = piece->get_all_possible_move_destinations(*this);
        for (const std::pair<int, int> position : all_possible_moves) {
            // if we were to move this piece to that position would it stop the check?
            const int old_x = piece->get_x();
            const int old_y = piece->get_y();
            Piece* destination_piece = m_board_squares[position.second][position.first].get_piece();

            // move the piece
            m_board_squares[piece->get_y()][piece->get_x()].set_piece(nullptr);
            m_board_squares[position.second][position.first].set_piece(piece.get());
            piece->set_position(position.first, position.second);

            // check for checks
            const bool still_in_check = king_is_in_check(is_white_piece);

            // undo move
            m_board_squares[old_y][old_x].set_piece(piece.get());
            m_board_squares[position.second][position.first].set_piece(destination_piece);
            piece->set_position(old_x, old_y);

            // auto exit when whe piece is not in check
            if (!still_in_check) return false;
        }
    }

    return true;
}

bool Board::king_is_in_check(const bool is_white_piece) {
    // get the position of the king
    int king_x = 0;
    int king_y = 0;
    const char king_symbol = is_white_piece ? 'K' : 'k';
    for (const std::unique_ptr<Piece> &piece : m_pieces) {
        if (piece->get_symbol() == king_symbol) {
            king_x = piece->get_x();
            king_y = piece->get_y();
        }
    }

    for (const std::unique_ptr<Piece> &piece : m_pieces) {
        if (piece->can_move_to(king_x, king_y, *this) && piece->is_white_piece() != is_white_piece
            && m_board_squares[piece->get_y()][piece->get_x()].get_piece() == piece.get()) {
            return true;
        }
    }

    return false;
}

Piece* Board::get_last_moved_piece() const {
    return m_last_moved_piece;
}