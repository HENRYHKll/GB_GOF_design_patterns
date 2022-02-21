#include "BombIterator.h"
#include <vector>

BombIterator::BombIterator(std::vector<Bomb *> *allBombs) : index(-1), refVector(allBombs), ptr(nullptr) {
    ++(*this);
}

void BombIterator::reset() {
    index = -1;
    ptr = nullptr;
}

BombIterator & BombIterator::operator++()
{
    index = index + 1;
    if (index == -1)
        index = 0;
    if(index == refVector->size()) {
        index = -1;
        ptr = nullptr;
        return *this;
    }
    ptr = refVector->at(index);
    return *this;
}

BombIterator &BombIterator::operator--()
{
    if (index == -1) {
        index = refVector->size() - 1;
        ptr = refVector->at(index);
        return *this;
    }
    index = index - 1;
    if(index == -1) {
        index = -1;
        ptr = nullptr;
        return *this;
    }
    ptr = refVector->at(index);
    return *this;
}

Bomb & BombIterator::operator*()
{
        return *refVector->at(index);
}

bool BombIterator::operator==(const BombIterator & it) 
{
    if (index == it.index &&
        ptr == it.ptr &&
        refVector == it.refVector)
    {
        return true;
    }
    return false;
}

bool BombIterator::operator!=(const BombIterator & it)
{
    return !(*this == it);
}

BombIterator &BombIterator::operator=(const BombIterator& it) = default;
BombIterator::BombIterator(const BombIterator& rhs) = default;