
#include "Character.hpp"



string Character::print() {
        string lives , name  ;
        if(isAlive()){
            lives = to_string(this->getLives());
            name = this->name;
        } else{
            lives = "--";
            name =  "("+this->name + ")";
        }
        string s =  name +","+ lives +","+ this->location.toString() ;
        return s ;
}

double Character::distance(Character *other) {
    return this->getLocation().distance(other->location);
}
