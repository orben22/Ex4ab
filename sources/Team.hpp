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
        size_t size;
        std::array<Character*,maxTeam> myteam;
        Character *leader;
    public:
        Team(Character *leader);
        ~Team();
        void add(Character *newChar);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        virtual void print();
        Character *getLeader() const;
        void setLeader(Character *leader);

        size_t getSize() const;

        const std::array<Character *, maxTeam> &getMyteam() const;
    };
}

#endif //UNTITLED3_TEAM_H
