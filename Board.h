#ifndef CHECKERSWITHOOP_BOARD_H
#define CHECKERSWITHOOP_BOARD_H

#include "Piece.h"
#include "Move.h"
#include <vector>
#include "TypeDef.h"


class Piece;
class Move;

class Board {
private:
    Piece* boardArr[8][8];

public:
    Board();

    void applyMove(Move move);

    Piece* getPieceAt(Coordinate coord);

    void display();

    void display(const std::vector<Move>& possibleMoves);
};


#endif //CHECKERSWITHOOP_BOARD_H