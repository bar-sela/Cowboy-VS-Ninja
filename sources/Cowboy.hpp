//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_COWBOY_H
#define MARACHOTBTASK4_COWBOY_H

#include "Character.hpp"

class Cowboy : public Character {
    int numOfBullets ;

public:Cowboy(string name,Point l ) : Character(l,110,name) , numOfBullets(6) {}; /// LIVES == נקודות פגיעה
string print() override{
    return "";
};
bool hasbooltes(){
    return false;
}
void reload(){};
void shoot(Character*){};
int GetNumOfBullets(){
    return 0 ;
};



};


#endif //MARACHOTBTASK4_COWBOY_H
