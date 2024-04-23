#include "Player.h"
#include "Move.h"
#include "Coordinate.h"
#include "TextColor.h"
#include <iostream>
#include <string>
#include <vector>

Player::Player(bool isRed) : isRed(isRed) {

    this->previousMove = Move();
}

void Player::inputCoords(Coordinate& coord) const {

    std::string str;

    //Ask for input
    if(this->isRed) {

        RED;
        std::cout << "Red";
        NO_COLOR;
        std::cout << ", enter coords of piece ie(a1)\n";
    }
    else {

        BLACK;
        std::cout << "Black";
        NO_COLOR;
        std::cout << ", enter coords of piece ie(a1)\n";
    }

    //Take in the input
    std::cin >> str;

    //Verify the input is of correct data type and is within the bounds of the board
    while(std::cin.fail() || str.length() != 2 || !(str[0] <= Board::SIZE + 96 && str[0] >= 97) || !(str[1] >= 49 && str[1] <= Board::SIZE + 48)) {

        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "INPUT ERROR: Invalid coordinates. Enter again: ";
        std::cin >> str;
    }

    //change from string to integer and store it in a Coordinate
    coord.x = (int(str[1]) - 48);
    coord.y = int(str[0]) - 96;
}

Piece* Player::getPieceInput(Board board) const {

    Coordinate pieceCoord;

    inputCoords(pieceCoord);

    //Make sure the piece pointer isn't a null pointer
    while(board.getPieceAt(pieceCoord) == nullptr) {

        std::cout << "There is no piece there\n";
        inputCoords(pieceCoord);
    }

    //Make sure the Coordinates correspond to a square checkers move on
    while(!pieceCoord.isCheckerSquare()) {

        std::cout << "That is not a checker square\n";
        inputCoords(pieceCoord);
    }

    //Make sure the Player isn't moving the opposite color Piece
    while(board.getPieceAt(pieceCoord)->getIsRed() != this->isRed) {

        std::cout << "Please move your own piece!!!\n";
        inputCoords(pieceCoord);
    }

    return board.getPieceAt(pieceCoord);
}

int Player::getMoveInput(const std::vector<Move>& possibleMoves, Move& chosenMove) const {

    int moveNumber;

    //Ask for input and store it
    std::cout << "Select a number to move to\n";
    std::cin >> moveNumber;

    //Make sure that the input is the correct data type and is an option
    while(std::cin.fail() || moveNumber > possibleMoves.size() || moveNumber <= 0) {

        std::cin.clear();
        std:: cin.ignore(100, '\n');
        std:: cout << "INVALID INPUT. Please try another number." << std::endl;
        std:: cout << "Select a number to move to\n";
        std::cin >> moveNumber;
    }

    //For future implementation of changing the piece to move
    if(moveNumber == 0)
        return 0;

    //Stores the selected Move
    chosenMove = possibleMoves[moveNumber - 1];
    this->previousMove = chosenMove;
    //Status code
    return 1;
}

int Player::getMove(Board& board, Move& chosenMove) const {

    bool isGoodPiece = false;
    std::vector<Move> possibleMoves;

    board.display();

    //Asks for Piece until a move can be made with the piece chosen
    while (!isGoodPiece) {

        Piece *piece = this->getPieceInput(board);

        possibleMoves = piece->getPossibleMoves(board);

        if (possibleMoves.empty())
            std::cout << "That piece has no possible moves\n";
        else
            isGoodPiece = true;
    }

    board.display(possibleMoves);

    return this->getMoveInput(possibleMoves, chosenMove);
}


void Player::takeTurn(Board& board) {

    Move chosenMove;
    std::vector<Move> possibleJumps;

    //Gets and applies the Move selected by the Player
    this->getMove(board, chosenMove);
    board.applyMove(chosenMove);

    //Gets the possible jumps after the Move is made
    possibleJumps = board.getPieceAt(this->previousMove.getEndingCoord())->getPossibleJumps(board);

    //If there are jumps and the previous Move was a jump ask the user to select out of the possible jumps
    while(this->previousMove.getIsJump() && !possibleJumps.empty()) {

        board.display(possibleJumps);

        this->getMoveInput(possibleJumps, chosenMove);
        board.applyMove(chosenMove);

        possibleJumps = board.getPieceAt(this->previousMove.getEndingCoord())->getPossibleJumps(board);
    }
}