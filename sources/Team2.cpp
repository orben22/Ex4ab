//
// Created by or on 5/2/23.
//

#include "Team2.hpp"

void ariel::Team2::attack(ariel::Team *enemyTeam) {
    if (enemyTeam == nullptr) throw std::invalid_argument("enemy team can't be null");
    if (enemyTeam->stillAlive() == 0) throw std::runtime_error("the members of the enemy team must be alive");
    this->changeLeader();
    Character *charToAttack = this->getCloser(enemyTeam);
    if (charToAttack == nullptr) return;
    for (size_t i = 0; i < this->getSize(); i++) {
        Character *curr = getMyteam().at(i);
        if (curr != nullptr) {
            if (curr->isAlive()) {
                if (!curr->getType()) {
                    auto *cowboy = dynamic_cast<Cowboy *>(curr);
                    cowboy->shoot(charToAttack);
                }else {
                    auto *ninja = dynamic_cast<Ninja *>(curr);
                    if (ninja->distance(charToAttack)<=1) ninja->slash(charToAttack);
                    else ninja->move(charToAttack);
                }
                if (!charToAttack->isAlive()) {
                    charToAttack = this->getCloser(enemyTeam);
                    if (charToAttack == nullptr) return;
                }
            }
        }
    }
}

void ariel::Team2::print() {
    for (size_t i = 0; i < this->getSize(); i++) {
        if (this->getMyteam()[i] != nullptr) std::cout << this->getMyteam()[i]->print() << std::endl;
    }
}

ariel::Team2::Team2(ariel::Character *leader) : Team(leader) {}
