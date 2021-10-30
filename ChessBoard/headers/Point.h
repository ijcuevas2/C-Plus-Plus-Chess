//
// Created by ismael on 10/24/21.
//

#ifndef CHESS_POINT_H
#define CHESS_POINT_H


class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    // Copy constructor
    Point(const Point & point) {
        x = point.x;
        y = point.y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};


#endif //CHESS_POINT_H
