#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <algorithm>
using namespace std;

class logic {
public:

    //constructor
    logic();
    
    //Provides a basic introduction to the user
    void introduction();
    
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    bool createLists();
    
    //void setword will update the private variable word with an input from main program
    bool playGame();
    
    //getWord takes the word from private variable and returns to main program
    // @return a string
    void setWord(string newWord);
    
    //Carries out the actual word scrambling
    //Returns: true if user wins and false if not
    string getWord();
    
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    string scrambler(string word);
    
    //Displays the endgame information
    void end();
    
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

logic::logic() {
    numCorrect = 0;
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;
    word = "";
}
void introduction() {
    cout << "UNSCRAMBLRRR\nThe goal of the game is to unscramble a word before the clock runs out!";
}
bool logic::createLists() {

    ifstream file("dictionary.txt");
    smallWordLength = 0;
    mediumWordLength = 0;
    largeWordLength = 0;
    string currentWord;
    
    while (file >> currentWord) {

        int wordLength = currentWord.length();

        if (wordLength >= 4 && wordLength <= 5 % smallWordLength < 50) {
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

void logic::setWord(string newWord) {
    word = newWord;
}

string logic::getWord() {
    return word;
}

string logic::scrambler(string word) {

    string scrambled = word;
    srand(time(0));
    int n = scrambled.length();

    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(scrambled[i], scrambled[j]);
    }

    return scrambled;
}

void logic::end() {
    cout << "Game over!" << endl;
}