#ifndef BullCowEngine_h
#define BullCowEngine_h

#include <stdio.h>
#include <string>

struct BullCowCount {
    int Bulls = 0;
    int Cows = 0;
};

enum class GuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_lowercase
};

class BullCowEngine {
    public:
        BullCowEngine();
        void Reset();
        int GetMaxTries();
        int GetCurrentTry();
        int GetHiddenWordLength();

        bool IsGameWon();

        GuessStatus CheckGuessValidity(std::string);
        BullCowCount SubmitValidGuess(std::string);
        
    private:
        
};

#endif