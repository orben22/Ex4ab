//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_TEAM2_H
#define UNTITLED3_TEAM2_H

#include "Team.hpp"

namespace ariel {
    class Team2: public Team{
    public:
        Team2(Character* leader);

        void attack(Team *enemyTeam) override;

        void print() override;

    };
}

#endif //UNTITLED3_TEAM2_H
