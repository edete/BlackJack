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
    int count = 0;
    Shoe S(2);
    S.shuffle();
    S.shuffle();
    S.shuffle();

    for(int i = 0;i<100;i++){
    cout << S.Cards[i] << endl;
    }


    Round R1(S,&count);
    R1.Player.hit(S,&count);
    S.pull();
    R1.Player.hit(S,&count);
    S.pull();
    R1.Dealer.hit(S,&count);
    S.pull();
    R1.Dealer.hit(S,&count);
    S.pull();

    for(int i = 0;i<100;i++){
    cout << S.Cards[i] << endl;
    }

    cout << "Player Hand: ";
    R1.Player.getHand();

    cout << "Dealer Hand: ";
    R1.Dealer.getHand();

}