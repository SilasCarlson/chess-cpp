#include "Pawn.h"
#include "../Board.h"

bool Pawn::can_move_to(int const x, int const y, Board &board) const {
    const int allowed_movement = has_moved() ? 1 : 2;

    // forward movement
    if (get_x() == x &&
        (is_white_piece() && get_y() - y <= allowed_movement || !is_white_piece() && get_y() + y >= allowed_movement) &&
        board.get_board_square(x, y).is_empty()) {
        return true;
    }

    // diagonal movement (when attacking)
    if ((get_x() + 1 == x || get_x() - 1 == x) && get_y() - y == (is_white_piece() ? 1 : -1)) {
        if (!board.get_board_square(x, y).is_empty()) {
            return true;
        }

        // en pessant attacking
        BoardSquare pawn_board_square = board.get_board_square(x, y - (is_white_piece() ? -1 : 1));
        if (!pawn_board_square.is_empty()
            && pawn_board_square.get_piece()->is_white_piece() != is_white_piece()
            && pawn_board_square.get_piece()->get_base_symbol() == 'P'
            && board.get_last_moved_piece() == pawn_board_square.get_piece()
            && pawn_board_square.get_piece()->get_moves() == 1
            && (y == 2 || y == 5)) {
            // add the target pawn to the board's en passant target
            board.set_en_passant_target(pawn_board_square.get_x(), pawn_board_square.get_y());

            // exit
            return true;
        }
    }

    return false;
}
