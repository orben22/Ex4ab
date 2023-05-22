//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_NINJA_H
#define UNTITLED3_NINJA_H
#include "Character.hpp"
namespace ariel {
    class Ninja:public Character {
    private:
        int speed;
    public:
        Ninja(std::string name, Point location,int life, int speed);
        void move(Character *enemy);
        void slash (Character *enemy);
        int getSpeed() const;

        std::string print() const override;

        bool getType() const override;
    };
}

#endif //UNTITLED3_NINJA_H
