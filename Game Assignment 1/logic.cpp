

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
};//end class logic