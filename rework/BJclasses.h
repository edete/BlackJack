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

    void newRound() {
        Player.hand.clear();
        Dealer.hand.clear();
        hit("D");
        hit("D");
        hit("P");
        hit("P");
    }

    void getDHand() {
    if(Dealer.hand[0] == 1) {
            cout << "A";
        }
    else if(Dealer.hand[0] >= 10) {
        cout << "10";
    }
    else {
            cout << Dealer.hand[0];
        }
        cout << endl;
    }

    void getHand(string user) {
    
    if(user == "P"){
    for(vector<int>::iterator i = Player.hand.begin();i != Player.hand.end();i++) {
        if(*i==1) {
            cout << "A ";
        }
        else if(*i >=10){
            cout << "10 ";
        }
        else {
            cout << *i << " ";
        }
    }
    }
    else if(user == "D"){
    for(vector<int>::iterator i = Dealer.hand.begin();i != Dealer.hand.end();i++) {
        if(*i==1) {
            cout << "A ";
        }
        else if(*i >=10){
            cout << "10 ";
        }
        else {
            cout << *i << " ";
        }
    }
    }
    cout << endl;
    }

    int win() {
    if(value("P")>value("D") && value("P")<=21) {
        cout << "You win!" << endl;
        return 1;
    }
    else if(value("D")>value("P") && value("D")<=21){
        cout << "Dealer wins!" << endl;
        return 2;
    }
    else if(value("D") == value("P")) {
        cout << "Push." << endl;
        return 3;
    }
    else if(value("D")>21) {
        cout << "You win!" << endl;
        return 1;
    }
    else {
        cout << "No winner determined." << endl;
        return 0;
    }
    }

    int check() {
    if(value("P") > 21){
        cout << "Player Hand: ";
        getHand("P");
        cout << "Dealer Hand: ";
        getHand("D");
        cout << "Dealer wins!" << endl;
        return 2;
    }
    else if(value("P")==21 && Player.hand.size()==2) {
        cout << "Player Hand: ";
        getHand("P");
        cout << "Dealer Hand: ";
        getHand("D");
        cout << "You have Blackjack!" << endl;
        return 1;
    }
    else if(value("D")==21) {
        cout << "Player Hand: ";
        getHand("P");
        cout << "Dealer Hand: ";
        getHand("D");
        cout << "Dealer has Blackjack!" << endl;
        return 2;
    }
    return 0;
    }

    void playerStand() {
    while(value("D")<=21) {
        if(value("D")<=value("P") && value("D")<17){
            vector<int>::iterator i = s.Cards.begin();
            int card = *i;

            if(card < 7 && card > 1) {
                count++;
            }
            else if(card>=10 || card == 1) {
                count=count -1;
            }
            
            Dealer.hand.push_back(card);
            s.Cards.erase(s.Cards.begin());
        }
        else if(value("D")>=17) {
            break;
        }
        else {
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
        if(card < 7 && card > 1) {
            count++;
        }
        else if(card>=10 || card == 1) {
            count=count-1;
        }
    }
    else if(user == "D"){
        if(card < 7) {
        count++;
        }
        else if(card>=10) {
        count=count-1;
        }
    Dealer.hand.push_back(card);
    }
    s.Cards.erase(s.Cards.begin());
    
    }

    int value(string user) {
    vector<int> handvalue;
    int hvalue;

    if(user == "P"){
    int numcards = Player.hand.size();

    //Create the original value of the hand
    for(int i = 0;i<numcards;i++){
        if(Player.hand[i]==1){
            handvalue.push_back(11);
        }
        else if(Player.hand[i]==11 || Player.hand[i]==12 || Player.hand[i]==13){
            handvalue.push_back(10);
        }
        else {
            handvalue.push_back(Player.hand[i]);
        }
    }
    
    //Fix exceptions
    for(int i = 0;i<numcards;i++){
        if(handvalue[i]==11 && (std::accumulate(handvalue.begin(), handvalue.end(),0)) > 21) {
            handvalue[i] = 1;
        }
    }

    hvalue = std::accumulate(handvalue.begin(), handvalue.end(),0);
    
    return hvalue;
    }

    else if(user == "D"){
    int numcards = Dealer.hand.size();

    //Create the original value of the hand
    for(int i = 0;i<numcards;i++){
        if(Dealer.hand[i]==1){
            handvalue.push_back(11);
        }
        else if(Dealer.hand[i]==11 || Dealer.hand[i]==12 || Dealer.hand[i]==13){
            handvalue.push_back(10);
        }
        else {
            handvalue.push_back(Dealer.hand[i]);
        }
    }
    
    //Fix exceptions
    for(int i = 0;i<numcards;i++){
        if(handvalue[i]==11 && (std::accumulate(handvalue.begin(), handvalue.end(),0)) > 21) {
            handvalue[i] = 1;
        }
    }

    hvalue = std::accumulate(handvalue.begin(), handvalue.end(),0);
    
    return hvalue;
    }
    return hvalue;
    }

    void getCount() {
        cout << "Count: " << count << endl;
    }

};