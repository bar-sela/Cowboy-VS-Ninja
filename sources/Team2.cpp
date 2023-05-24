
#include "Team2.hpp"

void Team2::add(Character *c)
    {
        if (this->getSize() == 10 || c->getIsMember())
            throw std::runtime_error("");
        this->get_charactersArray()[(size_t)this->getSize()] = c;
        this->updateAfterADD(c);
    };


