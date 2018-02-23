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

	// Start a new game
	do {
		NewGame.SetKeyPressed();
		// Start game
		if ( NewGame.GetGameCounter() == 2000 )
		{
			NewGame.MoveSnake();
		}

		// Print game intro
		// std::cout << NewGame.PrintIntro() << std::endl;
		NewGame.ReRenderMap();
	} while (NewGame.GetIsGameOver() != true);

	std::cout << std::endl << NewGame.GetGameOverText() << std::endl;

	echo();
	endwin();

	return 0;
};
