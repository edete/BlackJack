#ifndef SHOE_H
#define SHOE_H

#include "hand.h"
#include "rng.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

class Shoe {
    private:
        vector<int> Cards;
        
    public:
    friend class Hand;
    
    Shoe();

    Shoe(int n);

    void shuffle(Shoe s);

};



#endif