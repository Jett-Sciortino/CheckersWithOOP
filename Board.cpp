#include "Board.h"
#include <iostream>
#include <vector>
#include "TypeDef.h"

#ifdef _WIN32
#include <windows.h>
#define RED SetConsoleTextAttribute(hConsole, 4)
#define BLACK SetConsoleTextAttribute(hConsole, 8)
#define GOLD SetConsoleTextAttribute(hConsole, 14)
#define HIGHLIGHT SetConsoleTextAttribute(hConsole, 31)
#define NO_COLOR SetConsoleTextAttribute(hConsole, 7)
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

#define CENTER "\t\t\t\t\t\t\t\t\t\t"

Board::Board() {

    for(int y = 1; y < 9; y++) {

        for (int x = 1; x < 9; x++) {

            Coordinate coord = Coordinate(x, y);
            if(y < 4 && coord.isCheckerSquare())
                boardArr[y -1][x - 1] = new Piece(false, coord);
            else if(y > 5 && coord.isCheckerSquare())
                boardArr[y - 1][x - 1] = new Piece(true, coord);
            else
                boardArr[y - 1][x - 1] = nullptr;
        }
    }
}

void Board::display() {

    char rowLetter = 'a';
    std::cout << CENTER << "   1    2    3    4    5    6    7    8\n "
                        << CENTER << " +----+----+----+----+----+----+----+----+\n";

    for (int y = 0; y < 8; ++y) {

        std::cout << CENTER << rowLetter++;
        for (int x = 0; x < 8; ++x) {

            if (boardArr[y][x] != nullptr && boardArr[y][x]->getIsRed()) {
                std::cout << "| ";
                RED;
                std::cout << "RR ";
                NO_COLOR;

            } else if (boardArr[y][x] != nullptr && !boardArr[y][x]->getIsRed()) {
                std::cout << "| ";
                BLACK;
                std::cout << "BB ";
                NO_COLOR;
            } else
                std::cout << "|    ";
        }
        std::cout << "|\n "
                  << CENTER << " +----+----+----+----+----+----+----+----+\n";
    }
}



void Board::applyMove(Move move) {

    Coordinate start = move.getStartingCoord();
    Coordinate end = move.getEndingCoord();
    Piece *pieceToMove = boardArr[start.y - 1][start.x - 1];

    if (move.getIsJump()) {

        Coordinate average((start.x + end.x) / 2, (start.y + end.y) / 2);

        boardArr[start.y - 1][start.x - 1] = nullptr;
        boardArr[average.y - 1][average.x - 1] = nullptr;
        boardArr[end.y - 1][end.x - 1] = pieceToMove;
        pieceToMove->setCoordinate(end);
    }
    else {

        boardArr[start.y - 1][start.x - 1] = nullptr;
        boardArr[end.y - 1][end.x - 1] = pieceToMove;
        pieceToMove->setCoordinate(end);
    }


}

//In terms of board indexes
Piece *Board::getPieceAt(Coordinate coord) {

    return this->boardArr[coord.y - 1][coord.x - 1];
}

void Board::display(const std::vector<Move>& possibleMoves) {

    char rowLetter = 'a';
    int i = 0;

    std::cout << "   1    2    3    4    5    6    7    8\n +----+----+----+----+----+----+----+----+\n";


    for (int y = 1; y < 9; ++y) {

        std::cout << rowLetter++;

        for (int x = 1; x < 9; ++x) {


            bool moveFound = false;

            if (boardArr[y - 1][x - 1] != nullptr && boardArr[y - 1][x - 1]->getIsRed()) {
                std::cout << "| ";
                RED;
                std::cout << "RR ";
                NO_COLOR;

            } else if (boardArr[y - 1][x - 1] != nullptr && !boardArr[y - 1][x - 1]->getIsRed()) {
                std::cout << "| ";
                BLACK;
                std::cout << "BB ";
                NO_COLOR;
            }
            else {
                for (const auto &move: possibleMoves) {

                    if (move.getEndingCoord().x == x && move.getEndingCoord().y == y) {
                        std::cout << "| " << ++i << "  ";
                        moveFound = true;
                    }

                }

                if(!moveFound)
                    std::cout << "|    ";
            }
        }
        std::cout << "|\n +----+----+----+----+----+----+----+----+\n";
    }
}