//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_SMARTTEAM_HPP
#define MARACHOTBTASK4_SMARTTEAM_HPP

#include <vector>
#include "Team2.hpp"
#include <algorithm>


class SmartTeam : public Team {
protected:
    vector<Character *> allTeam;
    vector<Ninja *> CloseNinjas;
    vector<Cowboy *> CowboyVector;
    vector<Ninja *> NINJAVector;

public:
    SmartTeam(Character *leader) : Team(leader) {
        Team::add(leader);
    };

    void add(Character *c) override {
        Team::add(c);
        if (typeid(c).name() == typeid(Cowboy).name())
            this->CowboyVector.push_back(dynamic_cast<Cowboy *>(c));
        else
            NINJAVector.push_back(dynamic_cast<Ninja *>(c));
    }

    static void delete_vectorElements_from_vector(vector<Ninja *> v1, vector<Ninja *> v2) {
       for(int i = 0 ; i < v2.size(); i ++){
           for(int j = 0 ; j < v1.size(); j ++){
               if(v1.at(i) == v2.at(j))
                   v1.erase(v1.begin()+ i);
            }
        }
    }
    static Character* getRandomAliveMember( array<Character *, 10> characters){
        for(auto member : characters){
            if(member->isAlive())
                return member;
        }
        return nullptr;
    }


    Character *foundVictim(Team *attackedTeam , vector<Ninja*>& ninja_copy_vector) {
        /// intilize the maximum number of closed attacking characters to victim from attackedTeam
        int maximum_Attackers = 0;

        Character *nextVictim = nullptr ;


        /// loop all potential victims
        for (Character *potenialVictim: attackedTeam->get_charactersArray()) {
            if(!potenialVictim->isAlive())
                continue;

            int counter_close_ninjas = 0;
            vector<Ninja *> close_Ninjas_to_potenial_victim;
            int number_of_close_ninjas_needed = ceil(potenialVictim->getLives() / 40.0);/// example : 110 lives -> no need more then 3 close ninjas


            for (Ninja *attackerNinja: this->NINJAVector) {
                if(!attackerNinja->isAlive())
                    continue;

                if (potenialVictim->distance(attackerNinja) <= 1) {
                    counter_close_ninjas++;
                    close_Ninjas_to_potenial_victim.push_back(attackerNinja);
                }

                /// cheaking if this potential victim has the most closeNinjas meanwhile
                if (counter_close_ninjas > maximum_Attackers) {
                    /// update all of them
                    maximum_Attackers = counter_close_ninjas;   ///
                    nextVictim = potenialVictim;
                    this->CloseNinjas = close_Ninjas_to_potenial_victim;
                }
                /// for every potintail victim we dont need more ninjas closed to him then the amount of ninjav needed to kill him
                if (counter_close_ninjas >= number_of_close_ninjas_needed)
                    break;  /// up to the next poteintial victim
            }
        }
        /// delete from ninja_copy_vector all the close ninjas to the choosen victim
        delete_vectorElements_from_vector(ninja_copy_vector, this->CloseNinjas);

        /// in Case - no close ninja to every Character -> peek random victim
        if(nextVictim == nullptr)
            getRandomAliveMember(this->characters);

        return nextVictim;
    }

    void attack(Team *attackedTeam) override {
        /// copy to both Cowboy vector and Ninja vector
        vector<Cowboy *> Copy_cowboy_vector(this->CowboyVector);
        vector<Ninja *> Copy_Ninja_vector(this->NINJAVector);


        for(Character* c : this->characters){
            /// if the attacked team is dead -> no need to attack
            if(!attackedTeam->stillAlive())
                return ;

            /// if the previus victim is dead found a new
            if(! this->victim->isAlive() )
                this->victim = foundVictim(attackedTeam, Copy_Ninja_vector);
            /// loop the close Ninjas vector :
            for(auto member : this->CloseNinjas){
                adapting_attack(this->CloseNinjas);
            }


        }
    }
    template<typename T>
        void adapting_attack(vector<T> vector) {
            for (auto member: vector) {
                if (typeid(*member) == typeid(Cowboy))
                    Cowboy_attack_in_team((Cowboy *) member, this->victim);
                else
                    Ninja_attack_in_team((Ninja *) member, this->victim);
            }
        }
    }

;
#endif //MARACHOTBTASK4_SMARTTEAM_HPP
