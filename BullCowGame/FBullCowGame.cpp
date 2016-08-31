#include "FBullCowGame.h"
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
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

bool FBullCowGame::CheckGuessValidity(FString) const
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

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// compare letters against the hidden word
			if (MyHiddenWord[MHWChar] == Guess[GChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}

			}
		}
	}

	return BullCowCount;
}
