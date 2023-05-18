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
    public:
        void setLocation(const Point &location);

    private:
        int life;
        bool isInTeam;
    public:
        Character(std::string name, int life, Point location);

        Character();

        virtual ~Character();

        bool isAlive() const;

        double distance(Character *other);

        void hit(int damage);

        virtual std::string print() const=0;

        const Point &getLocation() const;

        int getLife() const;

        const std::string &getName() const;

        bool getIsInTeam() const;

        void setIsInTeam();
    };
}

#endif //UNTITLED3_CHARACTER_H
