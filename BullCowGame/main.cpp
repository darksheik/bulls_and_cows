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
void PrintGuess(FText Guess);
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

	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// loop for the number of guesses
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game
		// print number of bulls and cows
		PrintGuess(Guess);
		std::cout << std::endl;
		BCGame.IncrementTry();
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

void PrintGuess(FText Guess) {
	std::cout << "You guessed: " << Guess << std::endl;
	return;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
