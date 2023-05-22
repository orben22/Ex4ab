//
// Created by or on 5/2/23.
//
#include <cmath>
#include "Point.hpp"
#include <iostream>

ariel::Point::Point(double valueOfX, double valueOfY): valueOfX(valueOfX), valueOfY(valueOfY) {}

double ariel::Point::distance(const ariel::Point &other) const {
    double disX= this->valueOfX - other.valueOfX;
    double disY= this->valueOfY - other.valueOfY;
    return sqrt(disX*disX + disY*disY);
}

std::string ariel::Point::print() const {
    return "("+ std::to_string(this->getX())+","+ std::to_string(this->getY())+")";
}

ariel::Point ariel::Point::moveTowards(const Point & source, const Point & destination, double distance) {
    if (distance < 0) {
        throw std::invalid_argument("distance can't be negative");
    }
    double disX = destination.valueOfX - source.valueOfX;
    double disY = destination.valueOfY - source.valueOfY;
    double res = std::sqrt(pow(disX,2) + pow(disY,2));
    if (res <= distance) {
        return destination;
    } else {
        double ratio = distance / res;
        Point result(source.valueOfX + ratio * disX, source.valueOfY + ratio * disY);
        return result;
    }
}

ariel::Point::Point(): valueOfX(0), valueOfY(0) {}

double ariel::Point::getX() const {
    return valueOfX;
}

void ariel::Point::setX(double newX) {
    this->valueOfX = newX;
}

double ariel::Point::getY() const {
    return valueOfY;
}

void ariel::Point::setY(double newY) {
    this->valueOfY = newY;
}

bool ariel::Point::operator==(const ariel::Point &rhs) const {
    return valueOfX == rhs.valueOfX &&
           valueOfY == rhs.valueOfY;
}

bool ariel::Point::operator!=(const ariel::Point &rhs) const {
    return !(rhs == *this);
}

ariel::Point &ariel::Point::operator=(const ariel::Point &other)=default;

ariel::Point::Point(ariel::Point &&other) noexcept=default;

ariel::Point::~Point()=default;

ariel::Point &ariel::Point::operator=(ariel::Point &&other) noexcept=default;

ariel::Point::Point(const ariel::Point &other) = default;


