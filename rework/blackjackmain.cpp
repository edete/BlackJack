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
    
    string Player = "P";
    string Dealer = "D";
    Round R1;
    R1.shuffle();
    R1.shuffle();
    R1.shuffle();
    R1.hit(Player);
    R1.hit(Player);


    for(int i = 0;i<100;i++){
    cout << R1.s.Cards[i] << endl;
    }

    cout << "Player Hand: ";
    R1.Player.getHand();

    cout << "Dealer Hand: ";
    R1.Dealer.getHand();

}