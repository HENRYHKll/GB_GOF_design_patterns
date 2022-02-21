#pragma once

#include <vector>
#include "Bomb.h"

class BombIterator {
private:

    std::vector<Bomb *> * refVector;
    Bomb *ptr;
    unsigned int index;

public:

    explicit BombIterator(std::vector<Bomb *> * allBombs);

    BombIterator(const BombIterator& rhs);

    void reset();

    BombIterator & operator++(); 

    BombIterator &operator--(); 

    Bomb & operator*(); 

    bool operator==(const BombIterator & it); 

    bool operator!=(const BombIterator & it);

    BombIterator &operator=(const BombIterator & it); 

};