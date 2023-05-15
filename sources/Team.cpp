//
// Created by or on 5/2/23.
//

#include "Team.hpp"

ariel::Team::Team(ariel::Character *leader) : leader(leader) {
    myteam[0] = leader;
}

ariel::Team::~Team() {

}

void ariel::Team::add(ariel::Character *newChar) {
}

void ariel::Team::attack(ariel::Team *enemyTeam) {
}

int ariel::Team::stillAlive() {
    return 0;
}

void ariel::Team::print() {
}

ariel::Character *ariel::Team::getLeader() const {
    return leader;
}

void ariel::Team::setLeader(ariel::Character *leader) {
    Team::leader = leader;
}

