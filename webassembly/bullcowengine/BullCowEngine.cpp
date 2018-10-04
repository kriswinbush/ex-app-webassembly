#include "./BullCowEngine.h"
#include <iostream>

#include <emscripten/bind.h>

using namespace emscripten;
int CurrentTry;
int MaxTries;
std::string HiddenWord;
bool IsIsogram;
bool GameIsWon;

BullCowEngine() { Reset(); };
int GetMaxTries() { return MaxTries; };
int GetCurrentTry() { return CurrentTry; };
bool IsGameWon() { return GameIsWon; };

void Reset() {
    constexpr int MAX_TRIES = 8;
    MaxTries = MAX_TRIES;
    const std::string HIDDEN_WORD = "planet";
    HiddenWord = HIDDEN_WORD;
    CurrentTry = 1;
    return;
};

int GetHiddenWordLength() {
    return HiddenWord.length();
};

GuessStatus CheckGuessValidity(std::string CurrGuess) {
    if(false) {
        return GuessStatus::Not_Isogram;
    } else if (false) {
        return GuessStatus::Not_lowercase;
    } else if (CurrGuess.length() != GetHiddenWordLength()) {
        return GuessStatus::Wrong_Length;
    } else {
        return GuessStatus::OK;
    }
    return GuessStatus::OK;
};

BullCowCount SubmitValidGuess(std::string Guess) {
    CurrentTry++;
    BullCowCount BullCowCount;
    int HiddenWordLength = GetHiddenWordLength();

    for (int i = 0; i < HiddenWordLength; i++) {
        for( int j = 0; j < HiddenWordLength; j++) {
            if(Guess[j] == HiddenWord[i]) {
                if ( i == j) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if(BullCowCount.Bulls == HiddenWordLength) {
        GameIsWon = true;
    } else {
        GameIsWon = false;
    }
    return BullCowCount;
};

EMSCRIPTEN_BINDINGS(engine) {
    class_<BullCowEngine>("BullCowEngine")
        .constructor<void>()
        .function("GetMaxTries", &GetMaxTries)
        .function("GetCurrentTry", &GetCurrentTry)
        .function("IsGameWon", &IsGameWon)
        .function("Reset", &Reset)
        .function("CheckGuessValidity", &CheckGuessValidity)
        .function("GetHiddenWordLength", &GetHiddenWordLength)
        .function("SubmitValidGuess", &SubmitValidGuess)
        .property("HiddenWord", &HiddenWord)
}