#include <iostream>
#include "headers/Game.hpp"
#include "headers/Map.hpp"
#include "headers/Snake.hpp"

int main()
{
	system("clear");
	// Create new game
	Game NewGame;

	// Set game intro
	NewGame.SetIntro();
	// Print game intro
	std::cout << NewGame.PrintIntro() << std::endl;

	// Start a new game
	// do {
	// 	std::cout << NewGame.StartGame() << std::endl;
	// 	// NewGame.SetKeyPressed(std::cin);
	// 	NewGame.SetKeyPressed();
	// } while (NewGame.GetIsGameOver() != true);

	// Start game (temporary way)
	std::cout << NewGame.StartGame() << std::endl;
	NewGame.SetKeyPressed();
	return 0;
};
