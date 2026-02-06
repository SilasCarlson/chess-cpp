#include "Queen.h"
#include "../Board.h"

bool Queen::can_move_to(int const x, int const y, Board &board) const {
    // straight movement
    if (get_x() == x) {
        // ensure there are no pieces in the way
        const int start_position = get_y() < y ? get_y() : y;
        const int final_position = get_y() > y ? get_y() : y;

        for (int i = start_position; i < final_position; i++) {
            if (i == get_y()) continue; // ignore self
            if (!board.get_board_square(x, i).is_empty()) return false;
        }

        return true;
    }

    if (get_y() == y) {
        // ensure there are no pieces in the way
        const int start_position = get_x() < x ? get_x() : x;
        const int final_position = get_x() > x ? get_x() : x;

        for (int i = start_position; i < final_position; i++) {
            if (i == get_x()) continue; // ignore self
            if (!board.get_board_square(i, y).is_empty()) return false;
        }

        return true;
    }

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