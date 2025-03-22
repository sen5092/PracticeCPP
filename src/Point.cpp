//
//  Point.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/13/22.
//

#include "Point.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Point pt) {
    os << "X: " << pt.x << " Y: " << pt.y << std::endl;
    return os;
}

Point::Point() {
    std::cout << "constructing!" << std::endl;
}

Point::Point(int x_, int y_) {
    x = x_;
    y = y_;
}

Point::~Point() {}

Point Point::operator+(const Point& pt) {
    Point newPt;
    newPt.x = x + pt.x;
    newPt.y = y + pt.y;

    return newPt;
}

Point operator*(const int mult, const Point& pt) {
    Point newPt;
    newPt.x = mult * pt.x;
    newPt.y = mult * pt.y;
    return newPt;
}
