//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_CHARACTER_H
#define MARACHOTBTASK4_CHARACTER_H


#include "Point.hpp"

using namespace std;
class Character {
private:
    Point location;
    int lives;
    string name ;
protected:
    Character( Point& location ,  int lives ,string &name  ) : location(location) , lives(lives) , name(name){}

public:
    string& getName(){
        return this->name;
    }
    bool isAlive{};
    Point& getLocation(){
        return this->location;
    }
    virtual string print() = 0;
    void hit(){
    }
    int getLives(){
        return this->lives;
    };
};










#endif //MARACHOTBTASK4_CHARACTER_H
