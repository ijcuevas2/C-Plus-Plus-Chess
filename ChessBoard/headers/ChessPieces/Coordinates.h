//
// Created by ismael on 11/27/21.
//

#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H

class Coordinates {
public:
    int sourceX;
    int sourceY;
    int targetX;
    int targetY;

    Coordinates(int sourceX, int sourceY, int destX, int destY): sourceX(sourceX), sourceY(sourceY), targetX(destX), targetY(destY) {
    }
};

#endif //CHESS_COORDINATES_H
