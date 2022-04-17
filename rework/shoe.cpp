#include "rng.h"
#include "shoe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

Shoe::Shoe() {
    //Creation of a deck
    vector<int> deck;
	for(int i = 1;i<13;i++) {
		for(int j = 0;j<4;j++){
			deck.push_back(i);
		}
	}
}
Shoe::Shoe(int n) {
    //Creation of a deck
    vector<int> deck;
	for(int i = 1;i<13;i++) {
		for(int j = 0;j<4;j++){
			deck.push_back(i);
		}
	}
	//Creation of 2 deck shoe
	Cards = deck;
    for(int i = 0;i<n;i++) {
	    for(vector<int>::iterator iter = deck.begin();iter != deck.end() ; iter++){
		    Cards.push_back(*iter);
	    }
    }
}

void Shoe::shuffle(Shoe s) {
    rng::tsc_seed seed;
	rng::rng128 gen(seed());

    int numcards = s.Cards.size();

	for (int k = 0; k < numcards; k++) {
    int r = k + gen() % (numcards - k); // careful here!
    swap(s.Cards[k], s.Cards[r]);
    }
}