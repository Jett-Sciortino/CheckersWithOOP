#ifndef CHECKERSWITHOOP_PLAYER_H
#define CHECKERSWITHOOP_PLAYER_H

#include "Board.h"
#include "Move.h"
#include <string>
#include "TypeDef.h"

class Board;
class Move;

class Player {
private:
    bool isRed;

    Piece* getPieceInput(Board board);

    Move getMoveInput(const std::vector<Move>& possibleMoves);

    void strToCoords(const char* str, Coordinate& coord);

    std::string getColor() const;

public:
    Player(bool isRed);

    void getMove(Board& board);
};

#endif //CHECKERSWITHOOP_PLAYER_H