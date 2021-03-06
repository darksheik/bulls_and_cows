#pragma once
#include <string>

// Making the syntax Unreal-friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value

	void Reset(); // TODO make a more rich return value

	// counts bulls & cows, and increases try #
	FBullCowCount SubmitValidGuess(FString);

// Please try and ignore this and focus on the interface above ^^
private:
	// See constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};