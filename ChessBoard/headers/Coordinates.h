//
// Created by ismael on 11/27/21.
//

#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H

#include <complex>

class Coordinates {
public:
    int sourceX;
    int sourceY;
    int destX;
    int destY;

    Coordinates(int sourceX, int sourceY, int destX, int destY): sourceX(sourceX), sourceY(sourceY), destX(destX), destY(destY) {
    }

    int actualDistance(int source, int dest);
    int absoluteDistance(int source, int dest);
    int xAbsoluteDistance();
    int yAbsoluteDistance();
};

#endif //CHESS_COORDINATES_H
