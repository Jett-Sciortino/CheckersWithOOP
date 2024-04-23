#include "Coordinate.h"
#include "Board.h"

Coordinate::Coordinate(int x, int y) {

    this->x = x;
    this->y = y;
}
Coordinate::Coordinate() {

    this->x = 0;
    this->y = 0;
}

bool Coordinate::isCheckerSquare() const {

    return this->x%2 != this->y%2;
}

bool Coordinate::isOnBoard() const {

    return this->x <= Board::SIZE && this->x > 0 && this->y <= Board::SIZE && this->y > 0;
}