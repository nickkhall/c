#include <iostream>
#include "headers/Game.hpp"
#include "headers/Map.hpp"
#include "headers/Snake.hpp"

int main()
{
	system("clear");
	// Create new game
	Game NewGame;

	// Start a new game
	// do {
	// 	std::cout << NewGame.StartGame() << std::endl;
	// } while (NewGame.GetIsGameOver() != true);

	// Set game intro
	NewGame.SetIntro();
	// Print game intro
	std::cout << NewGame.PrintIntro() << std::endl;

	// Start game (temporary way)
	std::cout << NewGame.StartGame() << std::endl;
	return 0;
};
