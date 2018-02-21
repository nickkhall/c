#include <iostream>
#include "headers/Game.hpp"
#include "headers/Map.hpp"
#include "headers/Snake.hpp"

int main()
{
	system("clear");
	// Create new game
	Game *NewGame = new Game;
	// Create new map
	// Map *MapInstance = new Map;

	// Set the game intro
	NewGame->SetIntro();
	// Print game intro
	std::cout << NewGame->PrintIntro() << std::endl;

	return 0;
};
