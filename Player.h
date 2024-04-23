#ifndef CHECKERSWITHOOP_PLAYER_H
#define CHECKERSWITHOOP_PLAYER_H

#include "Board.h"
#include "Move.h"
#include "Coordinate.h"
#include <string>
#include <vector>

class Board;
class Move;

/**
 * Player class which will be used to get player input
 */
class Player {

private:
    /**
     * Used for the color changing characters in the console
     */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /**
     * True if the player can move red pieces\n
     * False if the player can move black pieces
     */
    const bool isRed;

    /**
     * The previous move that the player made
     */
    mutable Move previousMove;

    /**
     * Asks the player for the piece to move with error correction
     * @param board the board state that is shown to the user
     * @return A pointer to the piece that the player selected
     */
    Piece* getPieceInput(Board board) const;

    /**
     * Asks the player for the move they want to make out of the options shown
     * @param possibleMoves A vector passed by reference to be changed in the method
     * @param chosenMove A Move passed by reference to be changed in the method
     * @return A status number for future implementation of changing the piece you want to move
     */
    int getMoveInput(const std::vector<Move>& possibleMoves, Move& chosenMove) const;

    /**
     * Gets the user input
     * @param coord Valid Coordinate that is inputed by the user
     */
    void inputCoords(Coordinate& coord) const;

    /**
     * Combines the getPieceInput and getMoveInput methods to get the Move that the player wants to make
     * @param board The
     * @param chosenMove
     * @return
     */
    int getMove(Board& board, Move& chosenMove) const;

public:
    /**
     * Constructs a Player object
     * @param isRed The color of the pieces that the Player will be able to move. True if the color is red
     */
    explicit Player(bool isRed);

    /**
     * Uses the getMove and then applies that move to the board. Then checks for multiple jumps
     * @param board The board object that will have the Move(s) be applied to
     */
    void takeTurn(Board& board);
};

#endif //CHECKERSWITHOOP_PLAYER_H