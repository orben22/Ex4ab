//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_CHARACTER_H
#define UNTITLED3_CHARACTER_H
#include "Point.hpp"
#include "iostream"
namespace ariel {
    class Character {
    private:
        Point location;
        std::string name;
        int life;
    public:
        Character(std::string name,int life,Point location);

        Character();

        bool isAlive();

        double distance(Character *other);

        void hit(int damage);

        virtual void print() const;

        const Point &getLocation() const;

        int getLife() const;

        const std::string &getName() const;
    };
}

#endif //UNTITLED3_CHARACTER_H
