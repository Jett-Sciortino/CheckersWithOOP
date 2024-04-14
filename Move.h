#ifndef CHECKERSWITHOOP_MOVE_H
#define CHECKERSWITHOOP_MOVE_H

#include "Piece.h"
#include "Board.h"
#include "TypeDef.h"

class Piece;
class Board;

class Move {
private:
    Coordinate start, end;
    bool isJump;

public:
    Move();

    Move(Coordinate start, Coordinate end, bool isJump);

    Coordinate getStartingCoord() const;

    Coordinate getEndingCoord() const;

    bool getIsJump();
};


#endif //CHECKERSWITHOOP_MOVE_H