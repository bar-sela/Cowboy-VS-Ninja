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
    bool isMember ;
protected:
    Character( Point& location ,  int lives ,string &name  ) : location(location) , lives(lives) , name(name), isMember(
            false) {}

public:
    virtual string print();
    string& getName(){
        return this->name;
    }
    void hit(int number){
        if(number < 0 )
            throw std::invalid_argument("");
        this->lives = max(0 , this->lives - number);
    };
    bool isAlive(){ return this->lives > 0 ;}
    Point& getLocation(){ return this->location;}
    double distance(Character* other );
   ////// getters & setters
    int getLives(){
        return this->lives;
    };
    bool getIsMember(){
        return this->isMember;
    }
    void setIsMember(){
        this->isMember = true;
    }
};










#endif //MARACHOTBTASK4_CHARACTER_H
