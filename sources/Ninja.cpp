//
// Created by or on 5/2/23.
//

#include "Ninja.hpp"

ariel::Ninja::Ninja(std::string name, ariel::Point location, int life, int speed):Character(name,life,location),speed(speed) {}

void ariel::Ninja::move(ariel::Character *enemy) {
}

void ariel::Ninja::slash(ariel::Character *enemy) {
}

