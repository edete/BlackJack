#ifndef HAND_H
#define HAND_H

#include "shoe.h"
#include "round.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Hand {
    private:
        vector<int> hand;

    public:
    friend class Round;

    Hand();

    Hand(Shoe s, int*count);

    int value();

    void hit(Shoe s, int* count);

    void getHand();

};



#endif