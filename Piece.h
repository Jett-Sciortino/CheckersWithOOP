#ifndef CHECKERSWITHOOP_PIECE_H
#define CHECKERSWITHOOP_PIECE_H

#include "Move.h"
#include "Board.h"
#include "Coordinate.h"
#include <vector>

class Move;
class Board;

/**
 * A piece in the game of checkers
 */
class Piece {
private:
    /**
     * The color of the piece. True if the color is red
     */
    const bool isRed;
    /**
     * The kingness of the piece. True if the piece is a king
     */
    bool isKing;
    /**
     * The Coordinate of the piece on the board
     */
    Coordinate coordinate;

public:

    /**
     * Constructor for a piece object
     * @param isRed true if the piece is a red piece
     * @param coordinate the Coordinate of the piece on the board
     */
    Piece(bool isRed, Coordinate coordinate);

    /**
     * Calculates all the possible moves a piece can make in its current state including jumps. It does not seek multiple jumps
     * @param board a board object that represent the state of the checkers game
     * @return a vector of Move objects
     */
    [[nodiscard]] std::vector<Move> getPossibleMoves(Board board) const;

    /**
     * Calculates only the possible jump moves a piece can make in its current state
     * @param board a board object that represent the state of the checkers game
     * @return a vector of Move objects
     */
    [[nodiscard]] std::vector<Move> getPossibleJumps(Board board) const;

    /**
     * Returns true if the piece is red
     */
    [[nodiscard]] bool getIsRed() const;

    /**
     * Sets the coordinate of the piece
     * @param coord the coordinate to be set to
     */
    void setCoordinate(Coordinate coord);

    /**
     * Sets the isKing member variable
     */
    void setIsKing(bool isKing);

    /**
     * Returns true if the piece can be promoted to a king
     */
    [[nodiscard]] bool checkIsKing() const;

    /**
     * Returns true if the piece is a king
     */
    [[nodiscard]] bool getIsKing() const;
};


#endif //CHECKERSWITHOOP_PIECE_H