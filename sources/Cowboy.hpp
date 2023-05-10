//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_COWBOY_H
#define UNTITLED3_COWBOY_H
#include "Character.hpp"
namespace ariel {
    int cowbotLife=110;
    class Cowboy: public Character {
    private:
        int numOfBullets;
    public:
        Cowboy(std::string name,Point location);
        void shoot(Character *enemy);
        bool hasBullets() const;
        void reload();

        int getNumOfBullets() const;
    };
}

#endif //UNTITLED3_COWBOY_H
