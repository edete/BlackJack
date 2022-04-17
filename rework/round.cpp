#include "hand.h"
#include "round.h"
#include "shoe.h"
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

Round::Round(Shoe s, int*count) {
    Hand Player(s, count);
    Hand Dealer(s, count);
}

int Round::win() {
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

void Round::playerStand(Shoe s, int* count) {
    while(Dealer.value()<21) {
        if(Dealer.value()<Player.value() && Dealer.value()<17){
            Dealer.hit(s,count);
        }
        else if(Dealer.value()>=17) {
            break;
        }
    }
}
