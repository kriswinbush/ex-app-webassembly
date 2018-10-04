#include <iostream>
#include <string>
#include <stdio.h>

#include <emscripten/bind.h>

using namespace emscripten;
/* void setBulls(int b) { Bulls = b; }
    int getBulls() { return Bulls; } */
/* void setCows(int c) { Cows = c; }
    int getCows() { return Cows; } */

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

class BullCowClassic {
    public:
        BullCowClassic(int x) :x(x) { Reset(); };
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
        //getters || setters
        std::string getHiddenWord() {
            return HiddenWord;
        };

        void setHiddenWord(std::string HiddenWord_) {
            HiddenWord = HiddenWord_;
        };

    private:
    int x;
        int CurrentTry;
        int MaxTries;
        std::string HiddenWord;
        bool IsIsogram;
        bool GameIsWon;
};

EMSCRIPTEN_BINDINGS(engine) {
    class_<BullCowClassic>("BullCowClassic")
        .constructor<int>()
        .function("GetMaxTries", &BullCowClassic::GetMaxTries)
        .function("GetCurrentTry", &BullCowClassic::GetCurrentTry)
        .function("IsGameWon", &BullCowClassic::IsGameWon)
        .function("Reset", &BullCowClassic::Reset)
        .function("CheckGuessValidity", &BullCowClassic::CheckGuessValidity)
        .function("GetHiddenWordLength", &BullCowClassic::GetHiddenWordLength)
        .function("SubmitValidGuess", &BullCowClassic::SubmitValidGuess);
    value_array<BullCowCount>("BullCowCount")
        .element(&BullCowCount::Bulls)
        .element(&BullCowCount::Cows);
    enum_<GuessStatus>("GuessStatus")
        .value("Invalid_Status", GuessStatus::Invalid_Status)
        .value("OK", GuessStatus::OK)
        .value("Not_Isogram,", GuessStatus::Not_Isogram)
        .value("Wrong_Length", GuessStatus::Wrong_Length)
        .value("Not_lowercase", GuessStatus::Not_lowercase);
}