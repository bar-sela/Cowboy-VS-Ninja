//
// Created by Nachshon on 5/16/2023.
//

#include "NInja.hpp"

void Ninja::move(Character * enemy) {
    /// protected does problem in TIDY so we used the Getters.
    Point p =  this->getLocation().moveTowards(this->getLocation() , enemy->getLocation() , this->speed );
    this->setLocation(p); //// ninja location is changed to the right point
}

void Ninja::slash(Character * enemy ) {

    if(!enemy->isAlive() || !this->isAlive() || this == enemy)
        throw std::runtime_error("");

    double distance = this->distance(enemy);
    if(distance < 1 && enemy->isAlive())
        enemy->hit(40);
}
