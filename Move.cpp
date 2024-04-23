#include "Move.h"
#include "Coordinate.h"

Move::Move() : start(Coordinate(0, 0)), end(Coordinate(0, 0)), isJump(false) {

}

Move::Move(Coordinate start, Coordinate end, bool isJump) {

    this->start = start;
    this->end = end;
    this->isJump = isJump;
}

Coordinate Move::getStartingCoord() const {

    return this->start;
}

Coordinate Move::getEndingCoord() const {

    return this->end;
}

bool Move::getIsJump() const {

    return this->isJump;
}