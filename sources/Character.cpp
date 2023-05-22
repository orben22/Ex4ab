#include "Character.hpp"

#include <utility>

bool ariel::Character::isAlive() const {
    return this->life>0;
}

double ariel::Character::distance(ariel::Character *other) {
    return this->location.distance(other->location);
}

void ariel::Character::hit(int damage) {
    if (damage<0) throw std::invalid_argument("damage can't be negative");
    this->life-=damage;
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

ariel::Character::Character(std::string name, int life, ariel::Point location):name(std::move(name)),life(life), location(location), isInTeam(
        false) {}

ariel::Character::Character(): location(0,0),life(0){}

void ariel::Character::setLocation(const ariel::Point &newLocation) {
    Character::location = newLocation;
}

bool ariel::Character::getIsInTeam() const {
    return isInTeam;
}

void ariel::Character::setIsInTeam() {
    this->isInTeam=!isInTeam;
}

ariel::Character &ariel::Character::operator=(ariel::Character &&other) noexcept=default;

ariel::Character::Character(ariel::Character &&other) noexcept=default;

ariel::Character::Character(const ariel::Character &other)=default;

ariel::Character &ariel::Character::operator=(const ariel::Character &other)=default;

ariel::Character::~Character() =default;


