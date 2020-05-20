#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main(int argc, const char* argv[])
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows:" << std::endl;
	std::cout << "You can guess the " << WORLD_LENGTH <<  " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	for (int count = 0; count < MaxTries; count++)
	{
		std::string guess = GetGuess();
		std::cout << "Your guess was " << guess << std::endl;
		std::cout << std::endl;
	}
}


std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ", Enter your guess: ";
	std::string guess = "";
	getline(std::cin, guess);
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to again?";
	std::string response = "";
	getline(std::cin, response);
	return (response[0] == 'y') || response[0] == 'Y';
}

