#include "Board.h"
#include "Player.h"

int main() {

    Board board;
    Player redPlayer(true);
    Player blackPlayer(false);

    while(true) {

        redPlayer.getMove(board);

        blackPlayer.getMove(board);
    }
    return 0;

}