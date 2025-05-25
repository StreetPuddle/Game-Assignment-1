#include <iostream>
#include <ctime>
#include "logic.h"

using namespace std;

int main() {

	logic game;//global variable
	srand(time(NULL));
	bool play = true;

	while (play) {

		game.introduction();
		game.ready();

		if (!game.createLists()) {
			cout << "Dictionary failure.";
			return -1;
		}

		time_t startTime = time(nullptr);
		int duration = 60;
		bool end = true;
		while (time(nullptr) - startTime < duration && end) {
			game.playGame();
			if (time(nullptr) - startTime > duration) {
				cout << "Time has ran out. 60 seconds has passed";
			}
			end = false;//ends game even if 60 seconds hadn't passed
		}

		game.end();
		play = game.playAgain();
	}
	return 0;
}
