#pragma once
#include <string>

// notice me!

class FBullCowGame {
public:
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	void IncrementTry();

// Please try and ignore this and focus on the interface above ^^
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};