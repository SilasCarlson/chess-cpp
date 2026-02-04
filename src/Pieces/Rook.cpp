#include "Rook.h"
#include "../Board.h"

bool Rook::is_legal_move(int const x, int const y, const Board &board) const {
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

    return false;
}
