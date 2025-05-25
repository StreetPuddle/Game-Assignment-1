#include <iostream>
#include <ctime>
#include "logic.h"
#include <thread>


using namespace std;

int main() {

	logic game;//global variable
	srand(time(0));
	bool play = true;

	while (play) {
		game.introduction();
		game.ready();

		if (!game.createLists()) {
			cout << "Dictionary failure.";
			return -1;
		}

		game.playGame();
		game.end();
		play = game.playAgain();
	}

	return 0;
}
