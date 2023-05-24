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
#include "TrainedNinja.hpp"
#include "Character.hpp"

namespace ariel{};

class Team {
protected:
    Character *victim;
    Character *leader;
    int size;
    bool isFirstAttack ;
    /// like arr Character*[10] in c. no need for pointer beacuse we already know the size we want - 10
    array<Character *, 10> characters;
public:
    Team(Character *leader) :victim(nullptr), leader(leader), size(0) , isFirstAttack(true)  {
        this->add(leader);
    };
    virtual void addToArray(Character *character);
    void identationBy1(int startDex);
   virtual void add(Character* c);
    int foundFirstIndexOfCowboy();
    int stillAlive();
    virtual void attack(Team* attackedTeam) ;
    void print();
    void foundNewVictim(Team *victims);
    static void Cowboy_attack_in_team(Cowboy* cowboy , Character* victim){
        cowboy->hasboolets() ? cowboy->shoot(victim) : cowboy->reload();
    }
    static void Ninja_attack_in_team(Ninja* ninja , Character* victim){
        double distance = ninja->distance(victim);
        distance > 1 ? ninja->move(victim) : ninja->slash(victim);
    }
    static Character* closestToLeader(Character* leader , array<Character *, 10>& array,int size);
    ~Team() {};


//// get
  int getSize(){
      return this->size;
  }
    void addSize(){
        this->size ++ ;
    }
    array<Character *, 10>& get_charactersArray(){
        return this->characters;
  }

  void updateAfterADD(Character* c ){
      this->size +=1 ;
      c->setIsMember();
  }
};



#endif //MARACHOTBTASK4_TEAM_HPP
