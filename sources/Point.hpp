//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_POINT_H
#define MARACHOTBTASK4_POINT_H





#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    double x;
    double y;

public:
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
    // Getter methods
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }
    bool operator == (const Point& other) const {
        return (this->x == other.x) && (this->y == other.y);
    }
    string toString() const {
        return  "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }
    double distance(const Point& other) const ;
    static Point  moveTowards(Point & src , Point & target, double r );
};













#endif //MARACHOTBTASK4_POINT_H
