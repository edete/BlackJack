#include "deal.h"
#include "rng.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string>

using namespace std;

string deal(){

	
	
	string card;


	rng::tsc_seed seed;
	rng::rng128 gen(seed());

	int dealcard = gen()%13;



	if (dealcard == 0) {

			card = "2";
			
		}

	if (dealcard == 1){

			card = "3";
			
		}

	if (dealcard == 2) {

			card = "4";
			
		}

	if (dealcard == 3) {

			card = "5";
			
		}
	if (dealcard == 4) {

			card = "6";
			
		}
	if (dealcard == 5) {

			card = "7";
		}
	if (dealcard == 6) {

			card = "8";
		}
	if (dealcard == 7) {

			card = "9";
		}
	if (dealcard == 8) {

			card = "10";
			
		}
	if (dealcard == 9) {

			card = "J";
			
		}
	if (dealcard == 10) {

			card = "Q";
			
		}
	if (dealcard == 11) {

			card = "K";
			
		}
	if (dealcard == 12) {

			card = "A";
			
		}

	return card;
}