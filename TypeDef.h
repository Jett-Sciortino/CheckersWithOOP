//
// Created by jetts on 4/12/2024.
//

#ifndef CHECKERSWITHOOP_TYPEDEF_H
#define CHECKERSWITHOOP_TYPEDEF_H


struct Coordinate {
    int x;
    int y;

    Coordinate(int x, int y) {

        this->x = x;
        this->y = y;
    }

    Coordinate() {

        this->x = 0;
        this->y = 0;
    }

    bool isCheckerSquare() {

        return this->x%2 != this->y%2;
    }

    bool isOnBoard() {

        return this->x <= 8 && this->x > 0 && this->y <= 8 && this->y > 0;
    }
};
#endif //CHECKERSWITHOOP_TYPEDEF_H