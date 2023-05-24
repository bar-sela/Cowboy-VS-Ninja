//
// Created by Nachshon on 5/16/2023.
//
#include "Character.hpp"
#include "Cowboy.hpp"


void Cowboy::shoot(Character *enemy) {
        if(!this->isAlive() || !enemy->isAlive() || enemy == this)
            throw std::runtime_error("");

        if(!this->hasboolets())
            return ;

        enemy->hit(10 );
        this->numOfBullets -= 1 ;
}
