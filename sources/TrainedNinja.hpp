//
// Created by Nachshon on 5/17/2023.
//

#ifndef MARACHOTBTASK4_TRAINEDNINJA_HPP
#define MARACHOTBTASK4_TRAINEDNINJA_HPP


#include "NInja.hpp"

class TrainedNinja : public Ninja{
public :
    TrainedNinja(string name ,Point l) : Ninja(l, 120, name, 12){};
    string print(){
        return "";
    };
};



#endif //MARACHOTBTASK4_TRAINEDNINJA_HPP
