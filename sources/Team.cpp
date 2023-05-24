//
// Created by Nachshon on 5/16/2023.
//

#include <limits>
#include "Team.hpp"


 void Team::add(Character* c) {
    this->addToArray(c);
    this->updateAfterADD(c);
}
void Team::addToArray(Character *character) {
    if (this->size == 10 || character->getIsMember())
        throw std::runtime_error("");

    if(typeid(*character).name() == typeid(Cowboy).name()) {
        this->characters[(size_t)size] = character;
        return;
    }

    int firstIndexOfcowboys = foundFirstIndexOfCowboy();
    //// no cowboys att all - put the ninja by order
    if(firstIndexOfcowboys == -1 )
        this->characters[(size_t)size] = character;
    else {
        identationBy1(firstIndexOfcowboys);
        this->characters[(size_t)firstIndexOfcowboys] = character;
    }
}
//// example :characters :  Ninja1, Ninja2, Ninja3 ,cowboy1 , cowboy2 . entering Ninja4
/// result :  Ninja1, Ninja2, Ninja3 ,Ninja4 ,cowboy1 , cowboy2
void Team::identationBy1(int startDex) {
    for (int dex = size; dex >= startDex; dex++) {
        this->characters[(size_t)dex + 1] = this->characters[(size_t)dex]; /// if there is 10 already - will throw exeption
    }
}
//// founds the first index of cowboy in charcters array , returnes -1 if there are none cowboys
int Team::foundFirstIndexOfCowboy() {
    for (int dex = 0; dex < this->size; dex++) {
        if (typeid(this->characters[(size_t)dex]).name() == typeid(Cowboy).name()) {
            return dex;
        }
    }
    return -1;
}

Character *Team::closestToLeader(Character* leader , array<Character *, 10> &array,int size) {
    Character *ans = nullptr;
    double currentSmallestDis = std::numeric_limits<double>::max();


    for (int i = 0; i < size; i++) {
        Character *teamMember = array[(size_t)i];
        if (teamMember->isAlive()) {
            double distanceToLeader = leader->distance(teamMember);

            if (distanceToLeader < currentSmallestDis) {
                currentSmallestDis = distanceToLeader;
                ans = teamMember;
            }
        }
    }
    return ans;
}
void Team::foundNewVictim(Team *victims){
        this->victim = closestToLeader(this->leader, victims->characters,victims->size);
        this->isFirstAttack = false;
}
void Team::attack(Team *attackedTeam) {

        if(attackedTeam == nullptr )
            throw std::invalid_argument("");
        if(attackedTeam->stillAlive() == 0 )
            throw std::runtime_error("");


        //// UPDATING the LEADER FIRST
        if(!this->leader->isAlive()) {
            Character *newLeader = closestToLeader(this->leader, this->characters,this->size);
            this->leader = newLeader;
        }

        for (int i =0 ; i < this->size; i++) {
            /// after attack of each member we need to ensure that the we are not attacking a dead enemy
            this->foundNewVictim(attackedTeam);
            /// if the hall other team is dead - return
            if(this->victim == nullptr)
                return;

            /// if team member is already dead - he cannot attack
            Character* teamMember = this->characters[(size_t)i];
            if(!teamMember->isAlive())
                continue;

            if (typeid(*teamMember) == typeid(Cowboy))
                Cowboy_attack_in_team((Cowboy*)teamMember, this->victim);
            else
                Ninja_attack_in_team((Ninja*)teamMember,this->victim);
        }
}

int Team::stillAlive() {
    int counter = 0 ;
    for (size_t i = 0 ; i < this->size; i ++) {
        if(this->get_charactersArray()[i]->isAlive())
            counter+=1;
    }
    return counter;
}

void Team::print() {
    for (size_t i =0 ; i < this->size; i ++) {
        Character*  teamMember = this->characters[i];
        teamMember->print();
    }
}





