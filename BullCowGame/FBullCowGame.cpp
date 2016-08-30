#include "FBullCowGame.h"
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

void FBullCowGame::IncrementTry()
{
	MyCurrentTry++;
	return;
}

// receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	IncrementTry();

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the hidden word
		if (MyHiddenWord[i] == Guess[i]) {
			BullCowCount.Bulls++;
		}
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (MyHiddenWord[i] == Guess[j] && MyHiddenWord[i] != Guess[i]) {
				BullCowCount.Cows++;
			}
		}
	}

	return BullCowCount;
}
