#include "Player.h"
#include "Move.h"
#include <iostream>
#include <string>
#include "TypeDef.h"

Player::Player(bool isRed) {

    this->isRed = isRed;
}

void Player::getMove(Board& board) {

    bool isGoodPiece = false;
    std::vector<Move> possibleMoves;

    board.display();

    while (!isGoodPiece) {

        Piece *piece = getPieceInput(board);

        possibleMoves = piece->getPossibleMoves(board);

        if (possibleMoves.empty())
            std::cout << "That piece has no possible moves";
        else
            isGoodPiece = true;
    }

    board.display(possibleMoves);
    Move chosenMove = this->getMoveInput(possibleMoves);

    board.applyMove(chosenMove);
}

Piece* Player::getPieceInput(Board board) {

    char pieceCoordStr[2];

    std::cout << this->getColor() << ", enter coords of piece ie(xy)\n";
    std::cin >> pieceCoordStr;

    Coordinate pieceCoord;

    strToCoords(pieceCoordStr, pieceCoord);

    return board.getPieceAt(pieceCoord);
}

Move Player::getMoveInput(const std::vector<Move>& possibleMoves) {

    int moveNumber;

    std::cout << "Select a number to move to\n";
    std::cin >> moveNumber;

    return possibleMoves[moveNumber - 1];
}

void Player::strToCoords(const char* str, Coordinate& coord) {

    coord.x = (int(str[1]) - 48);
    coord.y = int(str[0]) - 96;
}

std::string Player::getColor() const {

    if(this->isRed)
        return {"Red"};
    else
        return {"Black"};
}