//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_COWBOY_H
#define MARACHOTBTASK4_COWBOY_H

#include <sstream>
#include "Character.hpp"

class Cowboy : public Character {
    int numOfBullets ;

public:Cowboy(string name,Point l ) : Character(l,110,name) , numOfBullets(6) {}; /// LIVES == נקודות פגיעה

void shoot(Character* enemy);

string print() override {
        return Character::print() + ", C ";

    };
bool hasboolets(){
    return numOfBullets > 0 ;
}
void reload(){
    if(!this->isAlive())
        throw std::runtime_error("");
    this ->numOfBullets = 6 ;
};


///// getters
int GetNumOfBullets(){
    return 0 ;
};



};


#endif //MARACHOTBTASK4_COWBOY_H
