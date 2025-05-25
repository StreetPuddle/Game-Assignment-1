#ifndef LOGIC_H
#define LOGIC_H
#include <string>

using namespace std;

class logic {

public:

    //constructor
    logic();

    //Provides a basic introduction to the user
    void introduction();

    //checks if the player is ready to player after reading the intro
    //returns true if the player is ready and no option for false
    bool ready();

    //Opens a file and reads in the list of words that can be scrambled
    //Returns true if words inserted and false if not
    bool createLists();

    //game logic that goes through five rounds that use each of the arrays
    void playGame();

    //returns a random word from the first array
    string randomSmallArray();

    //returns a random word from the second array
    string randomMediumArray();

    //returns a random word from the third array
    string randomLargeArray();

    //takes in a word and scrambles it
    //returns a scrambled version of the parameter
    string scrambler(string word);

    //displays the endgame information
    void end();

    //asks the player if they would like to play again
    //returns true if they would and false if they don't
    bool playAgain();

private:
    int numCorrect,             //the number of correct words
        smallWordLength,       //length of word arrays
        mediumWordLength,
        largeWordLength;
    string smallWords[50];   //array of words of length 4-5
    string mediumWords[50];   //array of words of length 6-7
    string largeWords[50];   //array of words of length 8+   
    string word;
};//end class logic

#endif