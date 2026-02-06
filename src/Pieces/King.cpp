#include <cmath>
#include "King.h"

bool King::can_move_to(int const x, int const y, Board &board) const {
    if (abs(get_x() - x) <= 1 && abs(get_y() - y) <= 1) {
        return true;
    }

    return false;
}