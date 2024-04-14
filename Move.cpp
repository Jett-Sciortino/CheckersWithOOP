#include "Move.h"
#include "TypeDef.h"

Move::Move() {

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

bool Move::getIsJump() {

    return this->isJump;
}
