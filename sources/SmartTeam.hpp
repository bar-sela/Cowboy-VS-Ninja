//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_SMARTTEAM_HPP
#define MARACHOTBTASK4_SMARTTEAM_HPP

#include <vector>
#include "Team2.hpp"
#include <algorithm>


class SmartTeam : public Team2 {
protected:
    vector<int> CowboyVector;
    vector<Ninja *> NINJAVector;
    Character *victim;

public:
    SmartTeam(Character* leader): Team2(leader){
    };
    vector<int> chooseClosessVictimToOurNinjas(Team *t ,  vector<Ninja *>& CopyNinja) {
        bool done = false;
        int i = 0;
        int largest = 0;
        std::vector<int> ans;
        while (!done) {
            ///test a member of the other team. count how many close ninjas are they to him

            for (size_t j = 0; j < t->getSize(); j++) {

                int countCloseNinjaForEnemy = 0;
                std::vector<int> temp;   //// vector ans is the optimize temp
                Character *testedEnemy = t->get_charactersArray()[j];
                temp.push_back(j);

                if (!testedEnemy->isAlive())
                    continue;

                /// itereate all the Characters of other team for determine enemy
                for (size_t k = 0; k < this->size; k++) {
                    Character *curMember = this->characters[k];
                    string s = typeid(curMember).name();
                    /// we want to detect close ninjas . distance dosent effect the shoot of cowboys
                    if (typeid(curMember).name() != typeid(Ninja).name() || !curMember->isAlive())
                        continue;

                    double distacnce = testedEnemy->distance(curMember);
                    YoungNinja *curNinja = (YoungNinja *) curMember;
                    /// if the ninja is defined as close for this itertation upgrade the counter by 1
                    double value  = (distacnce - i * curNinja->getSpeed());
                    if (1 > max(value, 0.0)) {

                        countCloseNinjaForEnemy++;
                        CopyNinja.erase(CopyNinja.begin() + int(k) );
                        temp.push_back(k);
                        done = true;

                    }
                }
                /// if we found a character from other team with more close ninjas to him , temparary he is the next victim
                if (countCloseNinjaForEnemy > largest) {
                    largest = countCloseNinjaForEnemy;
                    ans = temp;
                }
            }
            i++;
        }
        return ans;
    }

    void swap(size_t i, size_t j) {
        Character *temp = this->characters[i];
        this->characters[i] = this->characters[j];
        this->characters[j] = temp;
    }

    void CoboysBefureNinjas() {

    }

    void attack2(Team *t) {
        vector<Ninja *> copyNINJAs = this->NINJAVector;
        int index;
        for (int times = 0; times < 2; times++) {
            vector<int> v = chooseClosessVictimToOurNinjas(t, copyNINJAs);
            /// get the ememy at v[0] , v[i] for i != 0 are the close Ninjas to enemy
            int indexOfNewenemy = v.at(0);
            v.erase(v.begin());
            int lives = t->get_charactersArray()[size_t(indexOfNewenemy)]->getLives();
            int number_of_ninjas_needed = (lives / 40);
            int numberOfcloseNinjas = v.size();

            /// numberOf close Ninja were passing to the begining of the array
            numberOfcloseNinjas < number_of_ninjas_needed ? index = numberOfcloseNinjas
                                                          : index = number_of_ninjas_needed;

            //// take close ninja to front of the array
            for (size_t i = 0; i < index; i++) {
                swap(i, size_t(v.at(0)));
                v.erase(v.begin());
            }
            int currentIndexInArr = index;
            //// preperae a list if the indexes of all the Cowboys

            for (size_t i = 0; i < size; i++) {
                if (typeid(this->characters[i]).name() == typeid(Cowboy).name())
                    this->CowboyVector.push_back(i);
            }
            //// put Cowboys right after the Ninja we already puted to kill the Vitcim
            if (this->CowboyVector.size() * 10 > lives % 40) {
                for (size_t i = 0; i * 10 < lives % 40 && i < this->CowboyVector.size(); i++) {
                    this->swap(i, size_t(this->CowboyVector.at(0)));
                    this->CowboyVector.erase(this->CowboyVector.begin());
                    index++;
                }
            }
        }
    }
    void attack(Team* t){
        vector<Ninja *> copyNINJAs = this->NINJAVector;
        attack2(t);
      ///// the attacking loop it-itself
        for(size_t k = 0 ; k < this->size; k ++){
            this->chooseClosessVictimToOurNinjas(t,copyNINJAs);
              Character* teamMember = this->characters[(size_t)k];
              if(!teamMember->isAlive())
                  continue;

              if (typeid(*teamMember) == typeid(Cowboy))
                  Cowboy_attack_in_team((Cowboy*)teamMember, this->victim);
              else
                  Ninja_attack_in_team((Ninja*)teamMember,this->victim);
          }

    }
    void add(Character* c ){
        Team2::add(c);
        if(typeid(c).name() != typeid(Cowboy).name())
            this->NINJAVector.push_back((Ninja*)c);
    }
};

#endif //MARACHOTBTASK4_SMARTTEAM_HPP
