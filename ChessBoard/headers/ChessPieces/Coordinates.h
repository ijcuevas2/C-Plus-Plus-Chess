//
// Created by ismael on 11/27/21.
//

#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H

class Coordinates {
public:
    int sourceX;
    int sourceY;
    int destX;
    int destY;

    Coordinates(int sourceX, int sourceY, int destX, int destY): sourceX(sourceX), sourceY(sourceY), destX(destX), destY(destY) {
    }
};

#endif //CHESS_COORDINATES_H
