//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_NINJA_H
#define MARACHOTBTASK4_NINJA_H

#include "Character.hpp"
class Ninja : public Character {
protected:
    int speed ;
protected:
    Ninja(Point &l , int lives , string &name,int speed) : Character(l, lives, name), speed(speed){};
public:
    void move(Character *);
    void slash(Character *);
    string print() override {
        return Character::print() + ", N ";
    };
    /// getters && setters
    virtual int getSpeed() = 0;

    void setLocation(Point& p){
        this->getLocation() = p ; /// getLoaction returnes &Point
    }
};


#endif //MARACHOTBTASK4_NINJA_H
