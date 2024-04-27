#include "Piece.h"
#include "Coordinate.h"
#include <vector>

Piece::Piece(bool isRed, Coordinate coordinate) : isRed(isRed) {

    this->coordinate = coordinate;
    this->isKing = false;
}

bool Piece::getIsRed() const {

    return this->isRed;
}

std::vector<Move> Piece::getPossibleMoves(Board board) const {

    std::vector<Move> moves(0);

    int pieceX = this->coordinate.x, pieceY = this->coordinate.y,
        yIncrement = 1, rows = 1;

    //Red Pieces move in the negative y direction
    if(this->isRed)
        yIncrement = -1;

    //Kings have two rows that they look at for normal moves
    if(this->isKing)
        rows = 2;

    //starting y value to look at
    int Y = pieceY + yIncrement;

    /*
     * Looks at all the spaces that the Piece cold possibly move to
     * and checks if that is space it could actually move to
     */
    for (int i = 0; i < rows; i++) {

            for (int X = pieceX - 1; X <= pieceX + 1; X += 2) {

                //Is it on the board?
                if (Coordinate(X, Y).isOnBoard()) {

                    //Is there a blank space there?
                    if (board.getPieceAt(Coordinate(X, Y)) == nullptr) {

                        //If so then add a Move to the vector
                        moves.emplace_back(this->coordinate, Coordinate(X, Y), false);
                    }
                }
            }

        Y -= 2 * yIncrement;
    }

    //Get all the possible jumps from that position and put them in the vector
    std::vector<Move> possibleJumps = this->getPossibleJumps(board);
    moves.insert(moves.end(), possibleJumps.begin(),possibleJumps.end());

    return moves;
}


std::vector<Move> Piece::getPossibleJumps(Board board) const {

    std::vector<Move> jumps(0);

    int pieceX = this->coordinate.x, pieceY = this->coordinate.y,
                 yIncrement = 2, rows = 1;

    //Checks two away from the Piece instead of 1
    if(this->isRed)
        yIncrement = -2;

    if(this->isKing)
        rows = 2;

    int Y = pieceY + yIncrement;

    /*
     * Same as the getPossibleMoves loop except that it looks at an intermediate space too
     */
    for (int i = 0; i < rows; i++) {

            for (int X = pieceX - 2; X <= pieceX + 2; X += 4) {

                Coordinate potentialEndingCoord(X, Y);

                //Is it on the board?
                if (potentialEndingCoord.isOnBoard()) {

                    //Intermediate piece
                    Coordinate averageCoord((X + pieceX) / 2, (Y + pieceY) / 2);
                    Piece* averagePiece = board.getPieceAt(averageCoord);

                    //Is ending piece pointer at ending Coordinate a null pointer?
                    //Is the intermediate piece pointer a null pointer?
                    //Is the intermediate piece the opposite color?
                    if (board.getPieceAt(potentialEndingCoord) == nullptr
                        && averagePiece != nullptr
                        && averagePiece->isRed != this->isRed) {


                        Move jumpMove = Move(this->coordinate, potentialEndingCoord, true);
                        jumps.push_back(jumpMove);
                    }
                }
            }

        Y -= 2 * yIncrement;
    }

    return jumps;
}

void Piece::setCoordinate(Coordinate coord) {

    this->coordinate = coord;
}

void Piece::setIsKing(bool isKing) {

    this->isKing = isKing;
}

bool Piece::checkIsKing() const {

    //Is it at the opposite end of the board?
    return this->isRed && this->coordinate.y == 1 || !this->isRed && this->coordinate.y == Board::SIZE;
}

bool Piece::getIsKing() const {

    return this->isKing;
}