#ifndef CHECKERSWITHOOP_MOVE_H
#define CHECKERSWITHOOP_MOVE_H

#include "Piece.h"
#include "Board.h"
#include "Coordinate.h"

class Piece;
class Board;
/**
 * A Move in the game of checkers
 */
class Move {
private:
    /**
     * The starting Coordinate of the Move
     */
    Coordinate start;
    /**
     * The ending Coordinate of the Move
     */
    Coordinate end;
    /**
     * True if the Move is a jumping move
     */
    bool isJump;

public:
    /**
     * Default constructor. Used for declaring std::vector<Move>
     */
    Move();

    /**
     * Constructs a Move object with the following parameters
     * @param start the starting Coordinate of the Move
     * @param end the ending Coordinate of the Move
     * @param isJump is true if the Move is a jumping move
     */
    Move(Coordinate start, Coordinate end, bool isJump);

    /**
     * @return the starting Coordinate of the Move
     */
    [[nodiscard]] Coordinate getStartingCoord() const;

    /**
     * @return the ending Coordinate of the Move
     */
    [[nodiscard]] Coordinate getEndingCoord() const;

    /**
     * returns true if the Move is a jump
     */
    [[nodiscard]] bool getIsJump() const;
};


#endif //CHECKERSWITHOOP_MOVE_H