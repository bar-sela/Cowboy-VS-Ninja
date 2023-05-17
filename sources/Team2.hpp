//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_TEAM2_HPP
#define MARACHOTBTASK4_TEAM2_HPP


#include "Character.hpp"
#include "Team.hpp"

class Team2 : public Team{
public:
    explicit Team2(Character* leader) : Team(leader){};
    void add(Character *c) override{};
};


#endif //MARACHOTBTASK4_TEAM2_HPP
