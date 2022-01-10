//
// Created by ismael on 1/8/22.
//

#include "../headers/Coordinates.h"

int Coordinates::actualDistance(int source, int dest) {
    return source - dest;
}

int Coordinates::absoluteDistance(int source, int dest) {
    return std::abs(actualDistance(source, dest));
}

int Coordinates::xAbsoluteDistance() {
    return absoluteDistance(sourceX, destX);
}

int Coordinates::yAbsoluteDistance() {
    return absoluteDistance(sourceY, destY);
}