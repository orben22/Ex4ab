//
// Created by or on 5/2/23.
//

#include "SmartTeam.hpp"

void ariel::SmartTeam::attack(ariel::Team *enemyTeam) {
    Team::attack(enemyTeam);
}

void ariel::SmartTeam::print() {
    Team::print();
}

ariel::SmartTeam::SmartTeam(ariel::Character *leader) : Team(leader) {}
