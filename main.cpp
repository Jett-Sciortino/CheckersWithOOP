#include "Board.h"
#include "Player.h"
#include <iostream>

int main() {

    std::cout << "***********************************************************************************************************************\n"
                 "|                                                                                                                     |\n"
                 "|                                             Welcome to Ultimate Checkers                                            |\n"
                 "|                                                                                                                     |\n"
                 "|                   Rules:                                                                                            |\n"
                 "|                1) Checkers can only move diagonally.                                                                |\n"
                 "|                2) At the start of the game checkers can only move toward the opposite side.                         |\n"
                 "|                3) Checkers can jump over opponent checkers and remove them from the board.                          |\n"
                 "|                4) Checkers may move backwards to their side when they become \"kings\" by reaching the last           |\n"
                 "|                   row of the opposite side.                                                                         |\n"
                 "|                5) The game ends when only one color is on the board or when a player can not move.                  |\n"
                 "|                                                                                                                     |\n"
                 "|                                     Press the enter key to play already!!!                                          |\n"
                 "|                                                                                                                     |\n"
                 "***********************************************************************************************************************\n";

    std::cin.ignore(100, '\n');

    //creates objects
    Board board;
    Player redPlayer(true);
    Player blackPlayer(false);

    //game loop, takes turns for each player and checks if the game is over every turn
    while(!board.isEndGame()) {

        redPlayer.takeTurn(board);
        if(board.isEndGame())
            break;

        blackPlayer.takeTurn(board);
    }
    return 0;

}