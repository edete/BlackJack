#include "BJclasses.h"
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

int main() {
    int win = 0;
    string Player = "P";
    string Dealer = "D";
    string action = "";
    Round R1;
    R1.count=0;
    R1.shuffle();
    R1.shuffle();
    R1.shuffle();

    while(R1.s.Cards.size() != 0){
        R1.newRound();
        win = R1.check();

        while(win == 0) {
            cout << "Player Hand: ";
            R1.getHand("P");

            cout << "Dealer Hand: ";
            R1.getDHand();

            cin>>action;

            if(action == "hit") {
                R1.hit(Player);
                win = R1.check();
                }
            else if(action == "stand"){
                R1.playerStand();
                cout << "Player Hand: ";
                R1.getHand("P");
                cout << "Dealer Hand: ";
                R1.getHand("D");
                win = R1.win();
                break;
                }
            else if(action == "count") {
                R1.getCount();
            }
            else if(action == "break"){
                R1.s.Cards.clear();
                break;
                }

        }
    }

    return 0;
}