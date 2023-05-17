//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_NINJA_H
#define MARACHOTBTASK4_NINJA_H

#include "Character.hpp"
class Ninja : public Character {
private:
    int speed ;
protected:
    Ninja(Point &l , int lives , string &name,int speed) : Character(l, lives, name), speed(speed){};
public:
    void move(Character *){};
    void slash(Character *){};
    int GetLivesStart(){
        return 0 ;
    }
};


#endif //MARACHOTBTASK4_NINJA_H
