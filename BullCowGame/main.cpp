#include <iostream>
#include <string>

using namespace std;

int main() {
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	
	// get a guess from the player
	cout << "Your guess, please: ";
	
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << endl << "You guessed: " << Guess << endl;

	return 0;
}