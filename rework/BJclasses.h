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
    int n = deck.size();
    Cards = deck;
    for(int i = 0;i<n;i++) {
	    for(vector<int>::iterator iter = deck.begin();iter != deck.end() ; iter++){
		    Cards.push_back(*iter);
	    }
    }
    }

};


class Hand {
    private:
        vector<int> hand;

    public:
    friend class Round;

    Hand() {
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


    void getHand() {
    int numcards = hand.size();
    for(vector<int>::iterator i = hand.begin();i != hand.end();i++) {
    cout << *i << " ";
    }
    cout << endl;
    }

};


class Round {
    public:
    Shoe s;
    int count;
    Hand Dealer;
    Hand Player;
    

    Round() {
    Shoe s;
    count = 0;
    shuffle();
    shuffle();
    hit("D");
    hit("D");
    hit("P");
    hit("P");
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

    void playerStand() {
    while(Dealer.value()<21) {
        if(Dealer.value()<Player.value() && Dealer.value()<17){
            vector<int>::iterator i = s.Cards.begin();
            int card = *i;
            Dealer.hand.push_back(card);
            if(card < 7) {
            count++;
            }
            else if(card>=10) {
                count--;
            }
            s.Cards.erase(s.Cards.begin());
        }
        else if(Dealer.value()>=17) {
            break;
        }
    }
    }

    void shuffle() {
    rng::tsc_seed seed;
	rng::rng128 gen(seed());

    int numcards = s.Cards.size();

	for (int k = 0; k < numcards; k++) {
    int r = k + gen() % (numcards - k); // careful here!
    swap(s.Cards[k], s.Cards[r]);
    }
    }

    void hit(string user) {
    vector<int>::iterator i = s.Cards.begin();
    int card = *i;

    if(user == "P"){
    Player.hand.push_back(card);
    }
    else if(user == "D"){
    Dealer.hand.push_back(card);
    }
    
    if(card < 7) {
        count++;
    }
    else if(card>=10) {
        count--;
    }
    s.Cards.erase(s.Cards.begin());
    }

};