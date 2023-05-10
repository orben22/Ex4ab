//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_POINT_H
#define UNTITLED3_POINT_H

namespace ariel {
    class Point {
    private:
        double x, y;
    public:
        double distance(Point p) const;

        void print();

        Point moveTowards(Point &src, Point &dest, double distance);

        Point(double x, double y);

        Point();

        double getX() const;

        void setX(double newX);

        double getY() const;

        void setY(double newY);

        static int stillAlive();

        bool operator==(const Point &rhs) const;

        bool operator!=(const Point &rhs) const;
    };
}

#endif //UNTITLED3_POINT_H
