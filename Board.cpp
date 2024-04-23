#include "Board.h"
#include "Coordinate.h"
#include <iostream>
#include <vector>

Board::Board() {

    for(int y = 1; y < SIZE + 1; y++) {

        for (int x = 1; x < SIZE + 1; x++) {

            Coordinate coord = Coordinate(x, y);

            //Creates Piece object
            if(y < 4 && coord.isCheckerSquare())
                boardArr[y -1][x - 1] = new Piece(false, coord);
            else if(y > SIZE - 3 && coord.isCheckerSquare())
                boardArr[y - 1][x - 1] = new Piece(true, coord);
            //Null pointer is used as an empty space
            else
                boardArr[y - 1][x - 1] = nullptr;
        }
    }
}

void Board::display() const {

    char rowLetter = 'a';

    //Top numbers
    for(int i = 1; i <= SIZE; i++)
        std::cout << "    " << i;

    std::cout << "\n ";

    //Top line
    for(int i = 1; i <= SIZE; i++)
        std::cout << "+----";

    std::cout << "+\n";

    //Prints the corresponding letter for the different Piece types i.e. Black King or Normal Red
    for (const auto& y: boardArr) {

        std::cout << rowLetter++;
        for (auto piece: y) {

            if(piece != nullptr) {
                if(piece->getIsKing()) {
                    if(piece->getIsRed()) {
                        std::cout << "| ";
                        //Changes the text color to gold for king
                        GOLD;
                        std::cout << "K";
                        //Changes the text color to red
                        RED;
                        std::cout << "R ";
                        //Changes the text color back to normal
                        NO_COLOR;
                    }
                    else {
                        std::cout << "| ";
                        GOLD;
                        std::cout << "K";
                        //Changes the text color to black
                        BLACK;
                        std::cout << "B ";
                        NO_COLOR;
                    }
                } else {
                    if(piece->getIsRed()) {
                        std::cout << "| ";
                        RED;
                        std::cout << "RR ";
                        NO_COLOR;
                    }
                    else {
                        std::cout << "| ";
                        BLACK;
                        std::cout << "BB ";
                        NO_COLOR;
                    }
                }
            }
            else
                std::cout << "|    ";
        }
        std::cout << "|\n ";

        //Lines in between rows
        for(int i = 1; i <= SIZE; i++)
            std::cout << "+----";

        std::cout << "+\n";
    }
}

void Board::display(const std::vector<Move>& possibleMoves) const {

    char rowLetter = 'a';

    for(int i = 1; i <= SIZE; i++)
        std::cout << "    " << i;

    std::cout << "\n ";

    for(int i = 1; i <= SIZE; i++)
        std::cout << "+----";

    std::cout << "+\n";

    for (int y = 1; y < SIZE + 1; ++y) {

        std::cout << rowLetter++;

        for (int x = 1; x < SIZE + 1; ++x) {

            bool moveFound = false;
            Piece* piece = boardArr[y - 1][x - 1];

            if(piece != nullptr) {
                if(piece->getIsKing()) {
                    if(piece->getIsRed()) {
                        std::cout << "| ";
                        GOLD;
                        std::cout << "K";
                        RED;
                        std::cout << "R ";
                        NO_COLOR;
                    }
                    else {
                        std::cout << "| ";
                        GOLD;
                        std::cout << "K";
                        BLACK;
                        std::cout << "B ";
                        NO_COLOR;
                    }
                } else {
                    if(piece->getIsRed()) {
                        std::cout << "| ";
                        RED;
                        std::cout << "RR ";
                        NO_COLOR;
                    }
                    else {
                        std::cout << "| ";
                        BLACK;
                        std::cout << "BB ";
                        NO_COLOR;
                    }
                }
            } else {

                //Used to display the possible moves
                for (int i=0; i < possibleMoves.size(); i++) {

                    if (possibleMoves[i].getEndingCoord().x == x && possibleMoves[i].getEndingCoord().y == y) {
                        std::cout << "| ";
                        //Changes the color of the text to be blue
                        HIGHLIGHT;
                        std::cout << i+1;
                        NO_COLOR;
                        std::cout << "  ";
                        moveFound = true;
                    }
                }

                if(!moveFound)
                    std::cout << "|    ";
            }
        }

        std::cout << "|\n ";

        for(int i = 1; i <= SIZE; i++)
            std::cout << "+----";

        std::cout << "+\n";
    }
}

Piece* Board::getPieceAt(Coordinate coord) const {

    return this->boardArr[coord.y - 1][coord.x - 1];
}

void Board::applyMove(Move move) {

    Coordinate start = move.getStartingCoord();
    Coordinate end = move.getEndingCoord();
    Piece* pieceToMove = boardArr[start.y - 1][start.x - 1];

    /*If it is a jump move change the starting position and the intermediate position to null pointer
     *Then change the ending position to the Piece that is being moved
     *Finally check to see if the piece can be promoted. If so, promote it
     */
    if (move.getIsJump()) {

        Coordinate average((start.x + end.x) / 2, (start.y + end.y) / 2);

        boardArr[start.y - 1][start.x - 1] = nullptr;
        boardArr[average.y - 1][average.x - 1] = nullptr;
        boardArr[end.y - 1][end.x - 1] = pieceToMove;
        pieceToMove->setCoordinate(end);
        if(pieceToMove->checkIsKing())
            pieceToMove->setIsKing(true);
    }
    //If it is not a jump everything is the same except that there is no intermediate position
    else {

        boardArr[start.y - 1][start.x - 1] = nullptr;
        boardArr[end.y - 1][end.x - 1] = pieceToMove;
        pieceToMove->setCoordinate(end);
        if(pieceToMove->checkIsKing())
            pieceToMove->setIsKing(true);
    }
}

bool Board::isEndGame() const {

    bool redPieceFound = false;
    bool blackPieceFound = false;
    bool redMoveFound = false;
    bool blackMoveFound = false;

    //Check if there are any red or black pieces and if there are red or black moves
    for (auto &y: boardArr) {
        for (auto currentPiece: y) {

            if(currentPiece != nullptr) {

                bool currentIsRed = currentPiece->getIsRed();
                //Did you find a red Piece or a black Piece?
                if ((!redPieceFound || !blackPieceFound)) {

                    if (currentIsRed)
                        redPieceFound = true;
                    else
                        blackPieceFound = true;
                }
                //Did you find a red Move or a black Move?
                if (!redMoveFound && currentIsRed || !blackMoveFound && !currentIsRed) {

                    if (!currentPiece->getPossibleMoves(*this).empty()) {

                        if (currentIsRed)
                            redMoveFound = true;
                        else
                            blackMoveFound = true;
                    }
                }
            }
        }
    }

    //Are there any red pieces?
    if (!redPieceFound) {

        this->display();

        RED;
        std::cout << "Red";
        NO_COLOR;
        std::cout <<" has no pieces left!!!\n";
        BLACK;
        std::cout << "Black";
        NO_COLOR;
        std::cout << " is the winner!!!!";
        return true;
    }
    //Are there any black pieces?
    else if (!blackPieceFound) {

        this->display();

        BLACK;
        std::cout << "Black";
        NO_COLOR;
        std::cout <<" has no pieces left!!!\n";
        RED;
        std::cout << "Red";
        NO_COLOR;
        std::cout << " is the winner!!!!";
        return true;
    }
    //Are there any red Moves?
    else if (!redMoveFound) {

        this->display();

        RED;
        std::cout << "Red";
        NO_COLOR;
        std::cout <<" has no moves!!!\n";
        BLACK;
        std::cout << "Black";
        NO_COLOR;
        std::cout << " is the winner!!!!";
        return true;
    }
    //Are there any black Moves?
    else if (!blackMoveFound) {

        this->display();

        BLACK;
        std::cout << "Black";
        NO_COLOR;
        std::cout <<" has no moves!!!\n";
        RED;
        std::cout << "Red";
        NO_COLOR;
        std::cout << " is the winner!!!!";
        return true;
    } else
        return false;
}