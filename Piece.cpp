#include "Piece.h"
#include <vector>
#include "TypeDef.h"

Piece::Piece(bool isRed, Coordinate coordinate) {

    this->isRed = isRed;
    this->coordinate = coordinate;
    this->isKing = false;
}

bool Piece::getIsRed() const {

    return this->isRed;
}

std::vector<Move> Piece::getPossibleMoves(Board board) {

    std::vector<Move> moves(0);

    int pieceX = this->coordinate.x, pieceY = this->coordinate.y,
        yIncrement = 1, rows = 1;

    if(this->isRed)
        yIncrement = -1;
    
    if(this->isKing)
        rows = 2;

    int Y = pieceY + yIncrement;

    for (int i = 0; i < rows; i++) {

            for (int X = pieceX - 1; X <= pieceX + 1; X += 2) {

                if (Coordinate(X, Y).isOnBoard()) {

                    if (board.getPieceAt(Coordinate(X, Y)) == nullptr) {

                        moves.emplace_back(this->coordinate, Coordinate(X, Y), false);
                    }
                }
            }

        Y -= 2 * yIncrement;
    }

    std::vector<Move> possibleJumps = this->getPossibleJumps(board);
    moves.insert(moves.end(), possibleJumps.begin(),possibleJumps.end());
    
    return moves;
}


std::vector<Move> Piece::getPossibleJumps(Board board) {

    std::vector<Move> jumps(0);

    int pieceX = this->coordinate.x, pieceY = this->coordinate.y,
                 yIncrement = 2, rows = 1;

    if(this->isRed)
        yIncrement = -2;

    if(this->isKing)
        rows = 2;

    int Y = pieceY + yIncrement;

    for (int i = 0; i < rows; i++) {

            for (int X = pieceX - 2; X <= pieceX + 2; X += 4) {

                if (Coordinate(X, Y).isOnBoard()) {
                    
                    Coordinate averageCoord((X + pieceX) / 2, (Y + pieceY) / 2);
                    Piece* averagePiece = board.getPieceAt(averageCoord);

                    if (board.getPieceAt(Coordinate(X, Y)) == nullptr
                        && averagePiece != nullptr
                        && averagePiece->isRed != this->isRed) {

                        jumps.emplace_back(this->coordinate, Coordinate(X,Y), true);
                    }
                }
            }

        Y -= 4 * yIncrement;
    }

    return jumps;
}

void Piece::setCoordinate(Coordinate coord) {

    this->coordinate = coord;
}