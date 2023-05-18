//
// Created by or on 5/2/23.
//

#include "Cowboy.hpp"

#include <utility>

ariel::Cowboy::Cowboy(std::string name, ariel::Point location) : Character(std::move(name), 120, location),
                                                                 numOfBullets(6) {
}

bool ariel::Cowboy::hasBullets() const {
    return this->numOfBullets > 0;
}

void ariel::Cowboy::shoot(ariel::Character *enemy) {
    if (!this->isAlive()) throw std::runtime_error("can't shoot because the cowboy is dead");
    if (!enemy->isAlive()) throw std::runtime_error("can't shoot on dead character");
    if (enemy == this) throw std::runtime_error("can't shoot on himself");
    if (hasBullets()) enemy->hit(10);
    else this->reload();
}

void ariel::Cowboy::reload() {
    if (this->isAlive()) this->numOfBullets = 6;
    else throw std::runtime_error("dead character can't do reload");
}

int ariel::Cowboy::getNumOfBullets() const {
    return numOfBullets;
}

std::string ariel::Cowboy::print() const {
    if (this->isAlive())
        return "(C) name:(" + this->getName() + ") life:(" + std::to_string(this->getLife()) + ") location:(" +
               this->getLocation().print() + ")";
    return "(C) name:(" + this->getName() + ") location:(" + this->getLocation().print() + ")";
}
