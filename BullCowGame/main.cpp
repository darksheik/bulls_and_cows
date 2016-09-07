/*
  This is the console executable, that makes use of the BullCow class
  This acts as the view in an MVC pattern, and is responsible for all user interaction.

  For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;

	std::cout << "\\  /   \n";
	std::cout << " OO    OO\n";
	std::cout << " ||    ||\n\n";
	std::cout << "Can you guess the " << WordLength;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have " << MaxTries << " tries." << std::endl;

	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

		std::cout << std::endl;
	}

	PrintGameSummary();
}

// loop continually until the user gives a valid guess
FText GetValidGuess() {
	EGuessStatus Status;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		// get a guess from the player
		std::cout << "Try " << CurrentTry << ". Your guess, please: ";


		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word without capital letters.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else {
		std::cout << "Better luck next time!" << std::endl;
	}
}
