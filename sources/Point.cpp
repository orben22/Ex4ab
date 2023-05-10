//
// Created by or on 5/2/23.
//

#include "Point.hpp"

ariel::Point::Point(double x, double y) {}

double ariel::Point::distance(ariel::Point p) const {
    return 0;
}

void ariel::Point::print() {}

ariel::Point ariel::Point::moveTowards(ariel::Point &src, ariel::Point &dest, double distance) {
    return ariel::Point(0, 0);
}

int ariel::Point::stillAlive() {
    return 0;
}

ariel::Point::Point():x(0),y(0) {}

double ariel::Point::getX() const {
    return x;
}

void ariel::Point::setX(double newX) {
    this->x = newX;
}

double ariel::Point::getY() const {
    return y;
}

void ariel::Point::setY(double newY) {
    this->y = newY;
}

bool ariel::Point::operator==(const ariel::Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool ariel::Point::operator!=(const ariel::Point &rhs) const {
    return !(rhs == *this);
}


