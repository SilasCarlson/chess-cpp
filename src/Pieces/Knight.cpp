#include <cmath>
#include "Knight.h"

bool Knight::can_move_to(int const x, int const y, Board &board) const {
    // L shape movement
    if ((abs(get_x() - x) == 2 && abs(get_y() - y) == 1) || (abs(get_x() - x) == 1 && abs(get_y() - y) == 2)) {
        // since this piece can jump over pieces we do not need to check for pieces in between (thank goodness)
        return true;
    }

    return false;
}
