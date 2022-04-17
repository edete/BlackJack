#ifndef ROUND_H
#define ROUND_H

#include "shoe.h"
#include "hand.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Round {
    public:
    Hand Dealer;
    Hand Player;

    Round(Shoe s, int*count);

    int win();

    void playerStand(Shoe s, int* count);

};


#endif
