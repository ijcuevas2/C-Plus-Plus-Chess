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

    Coordinates(int sourceX, int sourceY, int targetX, int targetY): sourceX(sourceX), sourceY(sourceY), targetX(targetX), targetY(targetY) {
    }

    Coordinates(const Coordinates & coordinates) {
        sourceX = coordinates.sourceX;
        sourceY = coordinates.sourceY;
        targetX = coordinates.targetX;
        targetY = coordinates.targetY;
    }
};

#endif //CHESS_COORDINATES_H
