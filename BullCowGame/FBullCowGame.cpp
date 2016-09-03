#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't isogram
	{   
		return EGuessStatus::Not_Isogram; // TODO Write function
	}
	else if (!IsLowercase(Guess)) // if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase; // TODO Write function
	}
	else if (Guess.length() != GetHiddenWordLength()) { // if the guess isn't the right length
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming the same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// compare letters against the guess
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

	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup our map

	for (auto Letter : Word) { // loop over each letter of Fstring
	   // convert letter to lowercase
		Letter = tolower(Letter);

		// check whether letter is already in map
		if (LetterSeen[Letter]) {
			return false; // we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true;
		}

	}


	// return true if we have exited the loop
	return true; 
}

bool FBullCowGame::IsLowercase(FString Word) const {
	if (Word.length() == 0) { return false; }

	for (auto Letter : Word) { // loop over each letter of Fstring
		if (!islower(Letter)) { return false; }
	}

	// return true if we have exited the loop
	return true;
}