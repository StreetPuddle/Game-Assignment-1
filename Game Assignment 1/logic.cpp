#include <iostream>
#include <fstream>
#include "logic.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

//constructor
logic::logic() {
    numCorrect = 0;
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;
    word = "";
}

//introduces the player to the game and explains how to play
void logic::introduction() {
    cout << "UNSCRAMBLRRR\nThe goal of the game is to unscramble a word before the clock runs out!\n" << endl;
}


//checks if the player is ready to play and doesn't continue utill they're ready
bool logic::ready() {
    string response;

    while (true) {
        cout << "Are you ready now? Y or N?\nResonse: ";
        cin >> response;
        cout << "\n";

        if (response == "Y" || response == "y") {
            return true;
        } else if (response == "N" || response == "n") {
            cout << "Well...";
        } else {
            cout << "Invalid input.";
        }
    }
}


//reads in txt file to create 3 arrays of words of different lengths
bool logic::createLists() {

    ifstream file("dictionary.txt");
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;
    string currentWord;
    
    while (file >> currentWord) {

        int wordLength = currentWord.length();

        if (wordLength >= 4 && wordLength <= 5 && smallWordLength < 50) {
            smallWords[smallWordLength++] = currentWord;
        } else if (wordLength >= 6 && wordLength <= 7 && mediumWordLength < 50) {
            mediumWords[mediumWordLength++] = currentWord;
        } else if (wordLength >= 8 && largeWordLength < 50) {
            largeWords[largeWordLength++] = currentWord;
        }
    }
    file.close();
    return(smallWordLength + mediumWordLength + largeWordLength) > 0;
}

//game logic that goes through five rounds that use each of the arrays
void logic::playGame() {

    numCorrect = 0;
    string original, scrambled, guess;

    for (int i = 0; i < 2; i++) {
        original = randomSmallArray();
        scrambled = scrambler(original);

        cout << "Unscramble this word: " << scrambled << "\n> ";
        cin >> guess;

        if (guess == original) {
            cout << "You guessed right!\n\n";
            numCorrect++;
        } else {
            cout << "Ya guessed wrongggg...\nThe word was: " << original << "\n\n";
        }
        scrambled = "";
    }

    for (int i = 0; i < 2; i++) {
        original = randomMediumArray();
        scrambled = scrambler(original);

        cout << "Unscramble this word: " << scrambled << "\n> ";
        cin >> guess;

        if (guess == original) {
            cout << "You guessed right!\n\n";
            numCorrect++;
        } else {
            cout << "Ya guessed wrongggg...\nThe word was: " << original << "\n\n";
        }
    }

    original = randomLargeArray();
    scrambled = scrambler(original);

    cout << "Unscramble this word: " << scrambled << "\n> ";
    cin >> guess;

    if (guess == original) {
        cout << "You guessed right!\n\n";
        numCorrect++;
    } else {
        cout << "Ya guessed wrongggg...\nThe word was: " << original << "\n\n";
    }
}


//returns a random word from the small array
string logic::randomSmallArray() {

    if (smallWordLength == 0) {
        return "";
    }
    int index = rand() % smallWordLength;
    return smallWords[index];
}

//returns a random word from the medium array
string logic::randomMediumArray() {

    if (mediumWordLength == 0) {
        return "";
    }
    int index = rand() % mediumWordLength;
    return mediumWords[index];
}

//returns a random word from the large array
string logic::randomLargeArray() {

    if (largeWordLength == 0) {
        return "";
    }
    int index = rand() % largeWordLength;
    return largeWords[index];
}

//scrables the word passed into the function then returns it
string logic::scrambler(string word) {

    string scrambled = word;
    int n = scrambled.length();

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(scrambled[i], scrambled[j]);
    }
    return scrambled;
}

//tells the player they reached the end of the game and tells them they're rating
void logic::end() {
    cout << "Game over!" << endl;
    cout << "Score: " << numCorrect << "/5\n" << endl;

    switch (numCorrect) {
    case 5:
        cout << "Absolutely bonkers, you're a mad lad.\n" << endl;
        break;
    case 4:
        cout << "Wow, almost perfect!\n" << endl;
        break;
    case 3:
        cout << "Not bad, there's certainly room for improvement!\n" << endl;
        break;
    case 2:
        cout << "You did your best... that's all that matters!\n" << endl;
        break;
    case 1:
        cout << "Are... you testing out what happens if you get only one right?\n" << endl;
        break;
    case 0:
        cout << "Yikes... diagnosis says you got a smooth brain!\n" << endl;
        break;
    }
}


//ask the player if they would like to play another round
bool logic::playAgain() {
    string response;

    while (true) {
        cout << "Would you like to play again? Y or N?\nResonse: ";
        cin >> response;
        cout << "\n";

        if (response == "Y" || response == "y") {
            return true;
        }
        else if (response == "N" || response == "n") {
            cout << "Thank you for playing my game, c ya!" << endl;
            return false;
        }
        else {
            cout << "Invalid input.";
        }
    }
}