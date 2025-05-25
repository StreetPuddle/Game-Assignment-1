#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
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

    //returns a word from the first array
    string randomSmallArray();

    //returns a word from the second array
    string randomMediumArray();

    //returns a word from the third array
    string randomLargeArray();
    
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

bool logic::playGame() {

    numCorrect = 0;
    string original, scrambled, guess;

    for (int i = 0; i < 2; i++) {
        original = randomSmallArray();
        scrambled = scrambler(original);

        cout << "Unscramble this word: " << scrambled << "\n> ";
        cin >> guess;

        if (guess == original) {
            cout << "You guessed right!\n";
            numCorrect++;
        } else {
            cout << "Ya guessed wrongggg...\nThe word was: %d\n", original;
        }
    }

    for (int i = 0; i < 2; i++) {
        original = randomMediumArray();
        scrambled = scrambler(original);

        cout << "Unscramble this word: " << scrambled << "\n> ";
        cin >> guess;

        if (guess == original) {
            cout << "You guessed right!\n";
            numCorrect++;
        } else {
            cout << "Ya guessed wrongggg...\nThe word was: %d\n", original;
        }
    }

    original = randomLargeArray();
    scrambled = scrambler(original);

    cout << "Unscramble this word: " << scrambled << "\n> ";
    cin >> guess;

    if (guess == original) {
        cout << "You guessed right!\n";
        numCorrect++;
    } else {
        cout << "Ya guessed wrongggg...\nThe word was: %d\n", original;
    }

    return numCorrect == 5;
}

void logic::setWord(string newWord) {
    word = newWord;
}

string logic::getWord() {
    return word;
}

string logic::randomSmallArray() {
    if (smallWordLength == 0) {
        return "";
    }
    int index = rand() % smallWordLength;
    return smallWords[index];
}

string logic::randomMediumArray() {
    if (mediumWordLength == 0) {
        return "";
    }
    int index = rand() % mediumWordLength;
    return mediumWords[index];
}

string logic::randomLargeArray() {
    if (largeWordLength == 0) {
        return "";
    }
    int index = rand() % largeWordLength;
    return largeWords[index];
}

string logic::scrambler(string word) {

    string scrambled = word;
    srand(time(0));
    int n = scrambled.length();

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(scrambled[i], scrambled[j]);
    }

    return scrambled;
}

void logic::end() {
    cout << "Game over!" << endl;
    cout << "Score: " << numCorrect << "/5\n" << endl;

    switch (numCorrect) {
    case 5:
        cout << "Absolutely bonkers, you're a mad lad." << endl;
        break;
    case 4:
        cout << "Wow, almost perfect!" << endl;
        break;
    case 3:
        cout << "Not bad, there's certainly room for improvement!" << endl;
        break;
    case 2:
        cout << "You did your best... that's all that matters!" << endl;
        break;
    case 1:
        cout << "Are... you testing out what happens if you get only one right?" << endl;
        break;
    case 0:
        cout << "Yikes... diagnosis says you got a smooth brain!" << endl;
        break;
    }
    cout << "C ya" << endl;
}