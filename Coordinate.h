#ifndef CHECKERSWITHOOP_COORDINATE_H
#define CHECKERSWITHOOP_COORDINATE_H

/**
 * A location on the 2D board
 */
struct Coordinate {
    /**
     * The horizontal component
     */
    int x;
    /**
     * The vertical component
     */
    int y;//stores x and y value

    /**
     * Coordinate constructor for coordinate object. Initializes x and y values
     * @param x the horizontal component between 1 and 8
     * @param y the vertical component between 1 and 8
     */
    Coordinate(int x, int y);

    /**
     * Default constructor for Coordinate object
     */
    Coordinate();

    /**
     * Returns true if the Coordinate represents a space that a checker piece can move to
     */
    bool isCheckerSquare() const;

    /**
     * Returns true if the Coordinate represents a space that is within the bounds of the board
     */
    bool isOnBoard() const;
};

#endif //CHECKERSWITHOOP_COORDINATE_H
