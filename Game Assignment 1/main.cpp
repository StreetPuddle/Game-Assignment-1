#include <iostream>
#include <allegro5/allegro.h>
#include "logic.cpp"
#include <ctime>

using namespace std;

void* input(ALLEGRO_THREAD* ptr, void* arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);

logic game;//global variable
bool finsihed = false;
bool timeOut = false;

int main() {
	
	//read the file into game.readFile()
	game.setWord("Frank");
	cout << game.getWord() << endl;
	srand(time(0));

	ALLEGRO_THREAD* create1 = NULL, * create2 = NULL;
	create1 = al_create_thread(input, NULL);
	create2 = al_create_thread(timer, NULL);

	while (!finsihed && !timeOut) {

		if (!finsihed && !timeOut) {
			al_start_thread(create1);
			al_start_thread(create2);
		} else {
			al_destroy_thread(create1);
			al_destroy_thread(create2);
		}
	}
	if (finsihed) {
		cout << "\n\tUser entered input and that ended the program\n";
	} else {
		cout << "\n\tTime ran out and that ended the program\n";
	}
	return 0;
}

//a pointer to a function that promtes the user for input
void *input(ALLEGRO_THREAD* ptr, void* arg) {

	finished = false;
	//while the finished is equal to false
	scrambledWord = game.getFirstWord();
	//print this out
	//get a word from the user
	//check the word from the user to the correct word
	answer = game.checkFirstWord(scrambleWord, UserInput);
	if (answer == true) {
		//guessed the correct word
	//if all five words were guess
		finsihed = true;
	}
	//end of the while
	return NULL;
}

//a pointer to a function that starts the timer and checks the change in
//finished, which is in the input thread
void* timer(ALLEGRO_THREAD* ptr, void* arg) {

	time_t startTime, currentTime;//times used to measure elapsed time
	startTime = time(NULL);
	currentTime = time(NULL);

	while (currentTime - startTime < 10 && !finsihed) {
		currentTime = time(NULL);
	}
	timeOut = true;
	return NULL;
}