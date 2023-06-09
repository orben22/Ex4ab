#ifndef SMARTTEAM_H
#define SMARTTEAM_H

#include <array>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team2.hpp"

namespace ariel {
    class SmartTeam : public Team2 {

    public:
        SmartTeam(Character *leader);

        void attack(Team *enemys) override;

    private:
        double enemyScore(Character *enemy, Team *enemyTeam, Character *attackingCharacter);

        std::vector<Character *> targetedEnemies;
    };
}

#endif 