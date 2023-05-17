//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_OLDNINJA_HPP
#define MARACHOTBTASK4_OLDNINJA_HPP


#include "NInja.hpp"

class OldNinja : public Ninja{
public :
    OldNinja (string name, Point l ) : Ninja(l, 150, name, 8){};
     string print() override{
         return "";
     };
};


#endif //MARACHOTBTASK4_OLDNINJA_HPP
