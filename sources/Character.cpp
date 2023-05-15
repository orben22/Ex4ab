#include "Character.hpp"

bool ariel::Character::isAlive() {
    return false;
}

double ariel::Character::distance(ariel::Character *other) {
    return 0;
}

void ariel::Character::hit(int damage) {
}

std::string ariel::Character::print() const {
    return "";
}

const ariel::Point &ariel::Character::getLocation() const {
    return this->location;
}

int ariel::Character::getLife() const {
    return this->life;
}

const std::string &ariel::Character::getName() const {
    return this->name;
}

ariel::Character::Character(std::string name, int life, ariel::Point location):name(name),life(life), location(location) {

}

ariel::Character::Character(): location(0,0){}


