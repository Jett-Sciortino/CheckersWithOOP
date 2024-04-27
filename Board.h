#ifndef CHECKERSWITHOOP_BOARD_H
#define CHECKERSWITHOOP_BOARD_H

#include "Piece.h"
#include "Move.h"
#include "Coordinate.h"
#include "TextColor.h"
#include <vector>

class Piece;
class Move;

/**
 * A state of the checkers game
 */
class Board {
public:
    /**
     * Used for outputting colored text to the console in windows
     */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
     * The length and width of the board
     */
    const static int SIZE = 8;
    /**
     * Constructs a Board object. Initializes it in the standard checkers starting state
     */
    Board();

    /**
     * Applies a Move to the board
     * @param move The Move to apply
     */
    void applyMove(Move move);

    /**
     * Gets the piece at a space on the board
     * @param coord the coordinates of the space
     * @return A pointer to a Piece object
     */
    [[nodiscard]] Piece* getPieceAt(Coordinate coord) const;

    /**
     * Displays the board to the console
     */
    void display() const;

    /**
     * Displays the board to the console with numbers in spaces to signify Move choices for the player
     * @param possibleMoves A vector of Move objects that stores the possible Moves a piece can make
     */
    void display(const std::vector<Move>& possibleMoves) const;

    /**
     * Returns true if it is the end of the game
     */
    [[nodiscard]] bool isEndGame() const;

private:
    /**
     * A 2d array of Piece pointers
     */
    Piece* boardArr[SIZE][SIZE];

};


#endif //CHECKERSWITHOOP_BOARD_H