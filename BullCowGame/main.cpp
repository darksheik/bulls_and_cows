#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(std::string Guess);
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

	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// loop for the number of guesses
	for (int i = 1; i <= MaxTries; i++) {
		std::string Guess = GetGuess();
		PrintGuess(Guess);
		std::cout << std::endl;
		BCGame.IncrementTry();
	}
}

// get a guess from the player
std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Your guess, please: ";

	std::string Guess = "";
	std::getline(std::cin, Guess);
    
	return Guess;
}

void PrintGuess(std::string Guess) {
	std::cout << "You guessed: " << Guess << std::endl;
	return;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
