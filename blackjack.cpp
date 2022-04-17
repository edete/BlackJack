#include "deal.h"
#include "rng.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

int main(){

	
	//Player Variables
	string playercard1 = deal();
	string playercard2 = deal();
	int pcard1val = value(playercard1);
	int pcard2val = value(playercard2);
	int ptotal = pcard1val + pcard2val;

	string *hand = new string[10];
	hand[0] = playercard1;
	hand[1] = playercard2;


	//Dealer Variables
	string dealercard1 = deal();
	string dealercard2 = deal();
	int dcard1val = value(dealercard1);
	int dcard2val = value(dealercard2);
	int dtotal = dcard1val + dcard2val;

	string *dhand = new string[10];
	dhand[0] = dealercard1;
	dhand[1] = dealercard2;


	//Hit card setup
	string hitcard;
	char input = 'H';


	//Starting Deal
	cout << "Dealer Hand: " << dealercard1 << " " << "#" << endl;

	cout << "Your Hand: " << playercard1 << " " << playercard2 << " Total: " << ptotal << endl;


	//Hit or Stand
	cout << "Hit or Stand? (H for hit; S for Stand)" << endl;
	cin >> input;


	//Hit
	int cardstoarr = 2;
	while(input == 'H'){

		

		//Add hitcard to hand and point total
		hitcard = deal();
		hand[cardstoarr] = hitcard;
		ptotal = ptotal + value(hitcard);


		//Read out whole hand for user
		for(int i = 0; i < cardstoarr+1; i++){

		cout << hand[i] << " ";

		}
		cout << "Total: " << ptotal << endl;

		cardstoarr++;

		//Check for Bust
		if(ptotal > 21){

			cout<< "Sorry, you busted!" << endl;
			return 0;
		}

		//Ask for hit or stand
		cout << "Hit or Stand?";
		cin >> input;
	}


	//Stand
	if (input == 'S'){

		cout << "Player Stood" << endl;
	}

	//Dealer hits until hand >= 17
	cout << "Dealer Hand: " << dealercard1 << " " << dealercard2 << endl;

	cardstoarr = 2;

	while(dtotal < 17){

		hitcard = deal();
		dhand[cardstoarr] = hitcard;
		dtotal = dtotal + value(hitcard);

		for(int i = 0; i < cardstoarr+1; i++){

		cout << dhand[i] << " ";

		}
		cout << "Dealer Total: " << dtotal << endl;
		cardstoarr++;
	}
	
	//Check if dealer busted
	if(dtotal > 21){

		cout << "Dealer busts. You win!" << endl;
		return 0;
	}


	//Who wins?
	if (dtotal > ptotal){

		cout << "Sorry, you lose!" << endl;

	}
	if (ptotal > dtotal){

		cout << "Congrats, you win!" << endl;
	}
	if (ptotal == dtotal){

		cout << "It's a push!" << endl;
	}

	delete [] hand;
	delete [] dhand;

	return 0;
}