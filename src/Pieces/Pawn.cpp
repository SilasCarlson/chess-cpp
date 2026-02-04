#include "Pawn.h"
#include "../Board.h"

bool Pawn::is_legal_move(int const x, int const y, const Board &board) const {
    const int allowed_movement = has_moved() ? 1 : 2;

    // forward movement
    if (get_x() == x &&
        (is_white_piece() && get_y() - y <= allowed_movement || !is_white_piece() && get_y() + y >= allowed_movement) &&
        board.get_board_square(x, y).is_empty()) {
        return true;
    }

    // diagonal movement (when attacking)
    if ((get_x() + 1 == x || get_x() - 1 == x) && get_y() - y == (is_white_piece() ? 1 : -1) && !board.get_board_square(x, y).is_empty()) {
        return true;
    }

    return false;
}
