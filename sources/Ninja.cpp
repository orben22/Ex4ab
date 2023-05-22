//
// Created by or on 5/2/23.
//

#include "Ninja.hpp"
#include "Point.hpp"
#include <utility>

ariel::Ninja::Ninja(std::string name, ariel::Point location, int life, int speed) : Character(std::move(name), life, std::move(location)),
                                                                                    speed(speed) {}

void ariel::Ninja::move(ariel::Character *enemy) {
    if (!this->isAlive()) throw std::runtime_error("dead ninja can't move");
    if (!enemy->isAlive()) throw std::runtime_error("can't move to dead character");
    if (enemy == this) throw std::runtime_error("can't move to himself");
    this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
}

void ariel::Ninja::slash(ariel::Character *enemy) {
    if (!this->isAlive()) throw std::runtime_error("dead ninja can't slash");
    if (!enemy->isAlive()) throw std::runtime_error("can't slash a dead character");
    if (enemy == this) throw std::runtime_error("can't slash himself");
    if (this->distance(enemy)<=1) enemy->hit(40);
}

int ariel::Ninja::getSpeed() const {
    return speed;
}

std::string ariel::Ninja::print() const {
    if (this->isAlive())
        return "(N) name:(" + this->getName() + ") life:(" + std::to_string(this->getLife()) + ") location:(" +
               this->getLocation().print() + ")";
    return "(N) name:(" + this->getName() + ") location:(" + this->getLocation().print() + ")";
}

bool ariel::Ninja::getType() const {
    return true;
}
