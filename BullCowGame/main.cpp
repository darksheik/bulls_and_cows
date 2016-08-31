/*
  This is the console executable, that makes use of the BullCow class
  This acts as the view in an MVC pattern, and is responsible for all user interaction.

  For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// application entry point
int main() {
	do {
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0; // exit the application
}

// introduce the game
void PrintIntro() {

	int32 WordLength = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WordLength;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have " << MaxTries << " tries." << std::endl;

	// loop for the number of guesses
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;
		std::cout << std::endl;

		std::cout << std::endl;
	}

	// TODO summarise game
}

// get a guess from the player
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Your guess, please: ";

	FText Guess = "";
	std::getline(std::cin, Guess);
    
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
