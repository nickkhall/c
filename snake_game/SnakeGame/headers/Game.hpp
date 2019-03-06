#include <iostream>
#include <array>
#include <ncurses.h>
#include <unistd.h>

// Headers
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Player.hpp"

#ifndef GAME
#define GAME

// Key Definitions
const int UpKey = 119;    // W Key
const int DownKey = 115;  // S Key
const int LeftKey = 97;   // A Key
const int RightKey = 100; // D Key
const int EscapeKey = 27;

class Game {
private:
	bool IsGameOver;
	std::string Intro;
	std::string KeyPressed;
	int KeyPlayerPressed;
	int GameCounter;
	std::string GameOverText;
	int col;
	int row;

	Snake NewSnake;
	Player NewPlayer;
	Map *MapInstance;

public:
	Game() {
		KeyPlayerPressed = 0;
		GameCounter = 0;
		MapInstance = new Map(NewSnake);
		IsGameOver = false;
		Intro = "";
		GameOverText = "Game Over";

		setlocale(LC_ALL, "");
		initscr();
		cbreak();
		curs_set(0);
		noecho();
		nodelay(stdscr, true);
		scrollok(stdscr, false);
		clearok(stdscr, true);
	}

	bool GetIsGameOver();
	bool SetIsGameOver();
	void RenderIntroCeiling();
	void RenderIntroText();
	void RenderIntroFloor();
	void SetIntro();
	std::string PrintIntro();
	std::string GetKeyPressed();
	void SetKeyPressed();
	void ReRenderMap();
	int GetGameCounter();
	void IncrementGameCounter();
	void ResetGameCounter();
	void MoveSnake();
	std::string GetGameOverText();
};
#endif
