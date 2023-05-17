//
// Created by Nachshon on 5/16/2023.
//

#ifndef MARACHOTBTASK4_YOUNGNINJA_HPP
#define MARACHOTBTASK4_YOUNGNINJA_HPP
#include "NInja.hpp"

class YoungNinja : public  Ninja{
public :
    YoungNinja(string name , Point l) : Ninja(l, 100, name, 14){};
    string print(){
        return "";
    };
};


#endif //MARACHOTBTASK4_YOUNGNINJA_HPP
