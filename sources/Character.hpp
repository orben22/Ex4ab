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

        virtual int getType () const=0; // 0=cowboy, 1=YoungNinja, 2=TrainedNinja, 3=OldNinja

        void setIsInTeam();

        Character &operator=(const Character &other);

        Character(const Character &other);

        Character(Character &&other) noexcept;

        Character &operator=(Character &&other) noexcept;
    };
}

#endif //UNTITLED3_CHARACTER_H
