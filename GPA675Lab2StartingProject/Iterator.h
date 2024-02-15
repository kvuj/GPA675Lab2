#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "BodyItem.h"

class Iterator
{
public:
    Iterator() : Iterator(nullptr) {};
    Iterator(BodyItem* refBodyItem) : mRefBodyItem{ refBodyItem } {};
    Iterator(Iterator const&) = default;
    Iterator& operator = (Iterator const&) = default;
    ~Iterator() = default;

    Iterator& operator++() { // pre-incrementation
        if (mRefBodyItem) {
            mRefBodyItem = mRefBodyItem->mNext;
        }
        return *this;
    }
    Iterator& operator++(int) { // post-incrementation
        Iterator temp(*this);
        ++(*this);
        return temp;
    }
    bool operator==(Iterator const& other) const {
        return mRefBodyItem == other.mRefBodyItem;
    }
    bool operator!=(Iterator const& other) const {
        return !operator==(other);
    }

    QPoint& operator*() { return mRefBodyItem->position; }
    QPoint* operator->() { return &mRefBodyItem->position; }
private:
    BodyItem* mRefBodyItem;
};

#endif //ITERATOR_H