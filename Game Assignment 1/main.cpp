#include <iostream>
#include <allegro5/allegro.h>
#include <ctime>
#include <ctime>
#include "logic.h"

using namespace std;
class logic;

int main() {

	logic game;//global variable
	srand(time(0));
	game.introduction();
	game.ready();

	if (!game.createLists()) {
		cout << "Dictionary failure.";
		return -1;
	}
	
	bool matchResult = game.playGame();
	game.end();

	return 0;
}
