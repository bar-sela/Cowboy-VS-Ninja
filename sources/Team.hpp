//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_TEAM_HPP
#define MARACHOTBTASK4_TEAM_HPP

#define EPS 0.0001 ;

#include <array>
#include "NInja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "Character.hpp"

namespace ariel{};

class Team {
    std::array<Character*, 10> characters ;
public:
    Team(Character* leader){};
    virtual void add(Character * character) {};
    int stillAlive(){
        return 0;
    };
    string print(){
        return "";
    };
    void attack(Team*){};
    ~Team(){};

    Character* getChARCTERinIndex(unsigned long  index){
        return  this->characters[index];
    }

    unsigned  long foundFirstIndexOfCowboy(){
        for(unsigned  long i = 0 ; i < 10 ; i++){
            if(typeid(this->characters[i]).name() == typeid(Cowboy).name())
                return i ;
        }
        return 0;
    }

};


#endif //MARACHOTBTASK4_TEAM_HPP
