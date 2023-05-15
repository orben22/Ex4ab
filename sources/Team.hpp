//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_TEAM_H
#define UNTITLED3_TEAM_H
#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "array"
namespace ariel {
    int const maxTeam=10;
    class Team {
    private:
        std::array<Character*,maxTeam> myteam;
        Character *leader;
    public:
        Team(Character *leader);
        ~Team();
        void add(Character *newChar);
        void attack(Team *enemyTeam);
        int stillAlive();
        void print();
        Character *getLeader() const;
        void setLeader(Character *leader);
    };
}

#endif //UNTITLED3_TEAM_H
