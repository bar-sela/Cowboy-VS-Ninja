//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_OLDNINJA_H
#define MARACHOTBTASK4_OLDNINJA_H


#include "NInja.hpp"

class oldNinja : public Ninja{
public :
    oldNinja (string name,Point &l ) : Ninja(l, 150, name, 8){};
     void print(){};
};


#endif //MARACHOTBTASK4_OLDNINJA_H
