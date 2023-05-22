//
// Created by or on 5/2/23.
//

#include "Team.hpp"
#include "limits"


ariel::Team::Team(ariel::Character *leader) {
    if (!leader->isAlive()) throw std::invalid_argument("leader can't be dead");
    if (leader == nullptr) throw std::invalid_argument("the leader can't be null");
    if (leader->getIsInTeam()) throw std::runtime_error("the leader is in another team already");
    this->leader=leader;
    this->leader->setIsInTeam();
    std::fill(myteam.begin(), myteam.end(), nullptr);
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
    if (enemyTeam== nullptr) throw std::invalid_argument("enemy team can't be null");
    if (enemyTeam->stillAlive()==0) throw std::runtime_error("the members of the enemy team must be alive");
    this->changeLeader();
    Character *charToAttack=this->getCloser(enemyTeam);
    if (charToAttack== nullptr) return;
    for (size_t i=0;i<this->size;i++){
        Character* curr=myteam[i];
        if (curr!= nullptr && !curr->getType()){
            if(curr->isAlive()){
                auto *cowboy = dynamic_cast<Cowboy *>(curr);
                cowboy->shoot(charToAttack);
                if (!charToAttack->isAlive()) {
                    charToAttack=this->getCloser(enemyTeam);
                    if (charToAttack== nullptr) return;
                }
            }
        }
    }
    for (size_t i=0;i<this->size;i++){
        Character* curr=myteam[i];
        if (curr!= nullptr && curr->getType()){
            if(curr->isAlive()){
                auto *ninja = dynamic_cast<Ninja *>(curr);
                if (ninja->distance(charToAttack)<=1){
                    ninja->slash(charToAttack);
                    if (!charToAttack->isAlive()) {
                        charToAttack=this->getCloser(enemyTeam);
                        if (charToAttack== nullptr) return;
                    }
                }
                else ninja->move(charToAttack);
            }
        }
    }

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

ariel::Character *ariel::Team::getCloser(ariel::Team *enemyTeam) {
    if (enemyTeam->stillAlive()==0) return nullptr;
    double minDis=std::numeric_limits<double>::max();
    Character* closer= nullptr;
    for (Character* character:enemyTeam->getMyteam()){
        if (character!= nullptr&&character->isAlive()){
            if (this->leader->distance(character)<minDis) {
                minDis = this->leader->distance(character);
                closer=character;
            }
        }
    }
    return closer;
}

void ariel::Team::changeLeader() {
    if (!this->leader->isAlive()){
        if (this->getCloser(this)!= nullptr) this->leader=this->getCloser(this);
    }
}

ariel::Team &ariel::Team::operator=(ariel::Team &&other) noexcept=default;

ariel::Team &ariel::Team::operator=(const ariel::Team &other)=default;

ariel::Team::Team(ariel::Team &&other) noexcept=default;

ariel::Team::Team(const ariel::Team &other)=default;

