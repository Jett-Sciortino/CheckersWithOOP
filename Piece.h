#ifndef CHECKERSWITHOOP_PIECE_H
#define CHECKERSWITHOOP_PIECE_H

#include "Move.h"
#include "Board.h"
#include <vector>
#include "TypeDef.h"

class Move;
class Board;

class Piece {
private:
    bool isRed, isKing;
    Coordinate coordinate;

public:

    Piece(bool isRed, Coordinate coordinate);

    std::vector<Move> getPossibleMoves(Board board);

    std::vector<Move> getPossibleJumps(Board board);

    bool getIsRed() const;

    void setCoordinate(Coordinate coord);
};


#endif //CHECKERSWITHOOP_PIECE_H