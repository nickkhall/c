#include <iostream>
#include <ncurses.h>
#include "headers/Game.hpp"
#include "headers/Map.hpp"
#include "headers/Snake.hpp"

using namespace std;

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
		NewGame.ReRenderMap();
	} while (NewGame.GetIsGameOver() != true);

	cout << endl << NewGame.GetGameOverText() << endl;

	echo();
	endwin();

	return 0;
};
