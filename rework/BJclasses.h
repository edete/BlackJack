#include "rng.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

class Shoe {    
        
    public: 
    
    vector<int> Cards;

    friend class Hand;
    
    Shoe() {
    //Creation of a deck
    vector<int> deck;
	for(int i = 1;i<13;i++) {
		for(int j = 0;j<4;j++){
			deck.push_back(i);
		}
	}
    }

    Shoe(int n) {
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

    void shuffle() {
    rng::tsc_seed seed;
	rng::rng128 gen(seed());

    int numcards = Cards.size();

	for (int k = 0; k < numcards; k++) {
    int r = k + gen() % (numcards - k); // careful here!
    swap(Cards[k], Cards[r]);
    }
    }

    void pull() {
        Cards.erase(Cards.begin());
    }
};


class Hand : public Shoe {
    private:
        vector<int> hand;

    public:
    friend class Round;

    Hand() {
        cout << "default" << endl;
    }

    Hand(Shoe s, int*count) { //creates a starter hand

    vector<int>::iterator i = s.Cards.begin();

    int card = *i;
    hand.push_back(card);
    s.Cards.erase(i);

    card = *i;
    hand.push_back(card);
    s.Cards.erase(i);
    }

    int value() {
    vector<int> handvalue;
    int numcards = hand.size();
    int value = 0;

    //Create the original value of the hand
    for(int i = 0;i<numcards;i++){
        if(hand[i]==1){
            handvalue.push_back(11);
        }
        else if(hand[i]==11 || hand[i]==12 || hand[i]==13){
            handvalue.push_back(10);
        }
        else {
            handvalue.push_back(hand[i]);
        }
    }
    
    //Fix exceptions
    for(int i = 0;i<numcards;i++){
        if(handvalue[i]==11 && (std::accumulate(handvalue.begin(), handvalue.end(),0)) > 21) {
            handvalue[i] = 1;
        }
    }

    value = std::accumulate(handvalue.begin(), handvalue.end(),0);
    
    return value;
    }

    void hit(Shoe s, int* count) {
    vector<int>::iterator i = s.Cards.begin();

    int card = *i;
    hand.push_back(card);
    }

    void getHand() {
    int numcards = hand.size();
    for(vector<int>::iterator i = hand.begin();i != hand.end();i++) {
    cout << *i << " ";
    }
    cout << endl;
    }

};


class Round : public Hand {
    public:
    Hand Dealer;
    Hand Player;

    Round(Shoe s, int*count) {
    Hand Player(s, count);
    Hand Dealer(s, count);
    }

    int win() {
    if(Player.value()>Dealer.value() && Player.value()<=21) {
        return 1;
        cout << "You win!" << endl;
    }
    else if(Dealer.value()>Player.value() && Dealer.value()<=21){
        return 0;
        cout << "Dealer wins!" << endl;
    }
    else if(Dealer.value()==Player.value()) {
        return 3;
    }
    else {
        cout << "No winner determined." << endl;
        return 2;
    }
    }

    void playerStand(Shoe s, int* count) {
    while(Dealer.value()<21) {
        if(Dealer.value()<Player.value() && Dealer.value()<17){
            Dealer.hit(s,count);
        }
        else if(Dealer.value()>=17) {
            break;
        }
    }
    }

};