//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_SMARTTEAM_H
#define UNTITLED3_SMARTTEAM_H

#include "Team.hpp"

namespace ariel {
    class SmartTeam: public Team{
        SmartTeam(Character* leader);

    public:
        void attack(Team *enemyTeam) override;

        void print() override;


    };
}

#endif //UNTITLED3_SMARTTEAM_H
