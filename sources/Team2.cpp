//
// Created by or on 5/2/23.
//

#include "Team2.hpp"

void ariel::Team2::attack(ariel::Team *enemyTeam) {
    Team::attack(enemyTeam);
}

void ariel::Team2::print() {
    for (size_t i=0;i<this->getSize();i++) std::cout<<this->getMyteam()[i]->print()<<std::endl;
}
