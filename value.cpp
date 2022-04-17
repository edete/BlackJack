#include "deal.h"
#include <iostream>
#include <string>
using namespace std;

int value(std::string card){

	int cardval;

	if (card == "2") {

			cardval = 2;
			
		}

	if (card == "3"){

			cardval = 3;
			
		}

	if (card == "4") {

			cardval = 4;
			
		}

	if (card == "5") {

			cardval = 5;
			
		}
	if (card == "6") {

			cardval = 6;
			
		}
	if (card == "7") {

			cardval = 7;
		}
	if (card == "8") {

			cardval = 8;
		}
	if (card == "9") {

			cardval = 9;
		}
	if (card == "10") {

			cardval = 10;
			
		}
	if (card == "J") {

			cardval = 10;
			
		}
	if (card == "Q") {

			cardval = 10;
			
		}
	if (card == "K") {

			cardval = 10;
			
		}
	if (card == "A") {

			cardval = 1;
	}		

	return cardval;

}