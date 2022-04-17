#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <string>

using namespace std;


int main(){

	srand(time(NULL));

	char on_off = 'y';
	int count = 0;
	int card;
	int guess;
	int ask;


	while(on_off == 'y'){

		card = rand() % 12;
		ask = rand() % 10;


		if (card == 0) {

			cout << "2" << endl;
			count = count + 1;
		}

		if (card == 1){

			cout << "3" << endl;
			count = count + 1;
		}

		if (card == 2) {

			cout << "4" << endl;
			count = count + 1;
		}

		if (card == 3) {

			cout << "5" << endl;
			count = count + 1;
		}
		if (card == 4) {

			cout << "6" << endl;
			count = count + 1;
		}
		if (card == 5) {

			cout << "7" << endl;
		}
		if (card == 6) {

			cout << "8" << endl;
		}
		if (card == 7) {

			cout << "9" << endl;
		}
		if (card == 8) {

			cout << "10" << endl;
			count = count - 1;
		}
		if (card == 9) {

			cout << "J" << endl;
			count = count - 1;
		}
		if (card == 10) {

			cout << "Q" << endl;
			count = count - 1;
		}
		if (card == 11) {

			cout << "K" << endl;
			count = count - 1;
		}
		if (card == 12) {

			cout << "A" << endl;
			count = count - 1;
		}

		sleep(1);

		if(ask == 5){

			cout << "Enter count guess: ";
			cin >> guess;

			if (guess == count){

			cout << "Correct" << endl;

		}
		else{

		cout << "Wrong it was: " << count << endl;
		}

		cout << "Keep going?: ";
		cin >> on_off;

		}


	}


	
	return 0;
}