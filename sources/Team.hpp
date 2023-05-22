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
        std::array<Character*,maxTeam> myteam{};
        Character *leader;
    public:
        explicit Team(Character *leader);
        virtual ~Team();
        Team(const Team &other);

        Team(Team &&other) noexcept;

        Team &operator=(const Team &other);

        Team &operator=(Team &&other) noexcept;
        void add(Character *newChar);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        virtual void print();
        Character *getLeader() const;
        void setLeader(Character *leader);
        Character *getCloser(Team *enemyTeam);
        size_t getSize() const;
        void changeLeader();
        const std::array<Character *, maxTeam> &getMyteam() const;
    };
}

#endif //UNTITLED3_TEAM_H
