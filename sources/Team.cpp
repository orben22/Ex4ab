//
// Created by or on 5/2/23.
//

#include "Team.hpp"
#include "typeinfo"


ariel::Team::Team(ariel::Character *leader) {
    if (!leader->isAlive()) throw std::invalid_argument("leader can't be dead");
    if (leader == nullptr) throw std::invalid_argument("the leader can't be null");
    if (leader->getIsInTeam()) throw std::invalid_argument("the leader is in another team already");
    myteam[0] = leader;
    size = 1;
}

ariel::Team::~Team() {
    for (auto &character: myteam) delete character;
}

void ariel::Team::add(ariel::Character *newChar) {
    if (!newChar->isAlive()) throw std::runtime_error("can't add a dead character to the team");
    if (newChar->getIsInTeam()) throw std::runtime_error("can't be in another team");
    if (size == maxTeam) throw std::runtime_error("max characters in the team");
    if (myteam[size] == nullptr) {
        myteam[size] = newChar;
        size++;
        newChar->setIsInTeam();
    }
}

void ariel::Team::attack(ariel::Team *enemyTeam) {
}

int ariel::Team::stillAlive() {
    int alive = 0;
    for (size_t i = 0; i < size; i++) if (myteam[i]->isAlive()) alive++;
    return alive;
}

void ariel::Team::print() {
    for (size_t i = 0; i < size; i++) {
        if (typeid(myteam[i]) == typeid(Cowboy))
            std::cout << myteam[i]->print() << std::endl;
    }
    for (size_t i = 0; i < size; i++) {
        if (typeid(myteam[i]) == typeid(Ninja))
            std::cout << myteam[i]->print() << std::endl;
    }
}

ariel::Character *ariel::Team::getLeader() const {
    return leader;
}

void ariel::Team::setLeader(ariel::Character *leader) {
    Team::leader = leader;
}

size_t ariel::Team::getSize() const {
    return size;
}

const std::array<ariel::Character *, ariel::maxTeam> &ariel::Team::getMyteam() const {
    return myteam;
}

