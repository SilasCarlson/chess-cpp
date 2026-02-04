#include <cmath>
#include "King.h"

bool King::is_legal_move(int const x, int const y, const Board &board) const {
    if (abs(get_x() - x) <= 1 && abs(get_y() - y) <= 1) {
        return true;
    }

    return false;
}