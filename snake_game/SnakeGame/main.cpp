#include <iostream>
#include "classes/Game.cpp"

int main()
{
	system("clear");
	// Create new game
	Game NewGame = new Game;

	// Start a new game
	// do {
	// 	std::cout << NewGame->StartGame() << std::endl;
	// } while (NewGame->GetIsGameOver() != true);

	// Set game intro
	NewGame->SetIntro();
	// Print game intro
	std::cout << NewGame->PrintIntro() << std::endl;

	// Start game (temporary way)
	std::cout << NewGame->StartGame() << std::endl;
	return 0;
};
