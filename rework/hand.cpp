#include "rng.h"
#include "shoe.h"
#include "hand.h"
#include <numeric>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Hand::Hand() {
    cout << "default" << endl;
}

Hand::Hand(Shoe s, int*count) { //creates a starter hand

    vector<int>::iterator i = s.Cards.begin();

    int card = *i;
    hand.push_back(card);
    s.Cards.erase(i);

    card = *i;
    hand.push_back(card);
    s.Cards.erase(i);
}

int Hand::value() {
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

void Hand::hit(Shoe s, int* count) {
    vector<int>::iterator i = s.Cards.begin();

    int card = *i;
    hand.push_back(card);
    s.Cards.erase(i);
}

void Hand::getHand() {
    int numcards = hand.size();
    for(int i = 0;i<numcards;i++){
    cout << hand[i] << " ";
    }
    cout << endl;
}