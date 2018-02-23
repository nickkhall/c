#include <iostream>
#include <ncurses.h>
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


	// Start game (temporary way)
	std::cout << NewGame.StartGame() << std::endl;
	// Start a new game
	do {
		NewGame.SetKeyPressed();
	} while (NewGame.GetIsGameOver() != true);

	std::cout << "Game Over." << std::endl;

	return 0;
};
