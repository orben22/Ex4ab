//
// Created by or on 5/2/23.
//

#include "Cowboy.hpp"

#include <utility>
ariel::Cowboy::Cowboy(std::string name, ariel::Point location) : Character(std::move(name),cowbotLife, location),numOfBullets(6) {
}

bool ariel::Cowboy::hasBullets() const {
    if (this->numOfBullets>0) return true;
    return false;
}

void ariel::Cowboy::shoot(ariel::Character *enemy) {
}

void ariel::Cowboy::reload() {
    this->numOfBullets=6;
}

int ariel::Cowboy::getNumOfBullets() const {
    return numOfBullets;
}

