#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// application entry point
int main() {
	PrintIntro();

	constexpr int NUM_GUESSES = 5;

	// loop for the number of guesses
	for (int i = 1; i <= NUM_GUESSES; i++) {
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

// introduce the game
void PrintIntro() {

	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	return;
}

// get a guess from the player
string GetGuessAndPrintBack() {

	cout << "Your guess, please: ";

	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << endl << "You guessed: " << Guess << endl;
	return Guess;
}