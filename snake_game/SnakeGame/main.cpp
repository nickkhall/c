#include <iostream>
#include "classes/Game.cpp"
#include "classes/Map.cpp"
#include "classes/Snake.cpp"

int main()
{
	system("clear");
	// Create a new Snake
	Snake *NewSnake = new Snake();

	// Create new map
	Map *MapInstance = new Map(NewSnake);

	// Create new game
	Game *NewGame = new Game(NewSnake, MapInstance);

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
