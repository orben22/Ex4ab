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

        int stillAlive();
    };
}

#endif //UNTITLED3_POINT_H
