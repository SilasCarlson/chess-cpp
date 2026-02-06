#include <cmath>
#include "Bishop.h"

#include "../Board.h"

bool Bishop::can_move_to(const int x, const int y, Board &board) const {
    // diagonal movement
    if (abs(get_x() - x) == abs(get_y() - y)) {
        // ensure there are no pieces in the way
        const int increment_x = x > get_x() ? 1 : -1;
        const int increment_y = y > get_y() ? 1 : -1;
        int current_x = get_x();
        int current_y = get_y();

        for (int i = get_x(); i != x; i += increment_x) {
            current_x += increment_x;
            current_y += increment_y;

            if (current_x == x && current_y == y
                && (board.get_board_square(current_x, current_y).get_piece() == nullptr
                    || board.get_board_square(current_x, current_y).get_piece()->is_white_piece() != is_white_piece()))
                return true;

            if (!board.get_board_square(current_x, current_y).is_empty()) return false;
        }

        return true;
    }

    return false;
}
