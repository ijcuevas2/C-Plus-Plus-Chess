//
// Created by ismael on 1/13/22.
//

#include "../headers/Coordinates.h"

int Coordinates::actualDistance(int source, int dest) {
    return source - dest;
}

int Coordinates::absoluteDistance(int source, int dest) {
    return std::abs(actualDistance(source, dest));
}

int Coordinates::xAbsoluteDistance() {
    return absoluteDistance(sourceX, targetX);
}

int Coordinates::yAbsoluteDistance() {
    return absoluteDistance(sourceY, targetY);
}