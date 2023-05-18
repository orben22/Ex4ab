//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_POINT_H
#define UNTITLED3_POINT_H

#include <string>

namespace ariel {
    class Point {
    private:
        double valueOfX, valueOfY;
    public:
        double distance(Point &other) const;

        std::string print() const;

        static Point moveTowards(const Point & source, const Point& destination, double distance);

        Point(double x, double y);

        Point();

        Point(Point &other);

        double getX() const;

        void setX(double newX);

        double getY() const;

        void setY(double newY);

        bool operator==(const Point &rhs) const;

        bool operator!=(const Point &rhs) const;
    };
}

#endif //UNTITLED3_POINT_H
