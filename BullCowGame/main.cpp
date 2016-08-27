#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuess(string Guess);

// application entry point
int main() {
	PrintIntro();
	PlayGame();
	return 0; // exit the application
}

// introduce the game
void PrintIntro() {

	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	return;
}

void PlayGame()
{
	// loop for the number of guesses
	constexpr int NUM_GUESSES = 5;
	for (int i = 1; i <= NUM_GUESSES; i++) {
		string Guess = GetGuess();
		PrintGuess(Guess);
		cout << endl;
	}
}

// get a guess from the player
string GetGuess() {

	cout << "Your guess, please: ";

	string Guess = "";
	getline(cin, Guess);
    
	return Guess;
}

void PrintGuess(string Guess) {
	cout << "You guessed: " << Guess << endl;
	return;
}