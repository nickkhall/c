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
const int UpKey = 119;
const int DownKey = 115;
const int LeftKey = 97;
const int RightKey = 100;
const int EscapeKey = 27;

class Game
{
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

		initscr();
		cbreak();
		noecho();
		nodelay(stdscr, TRUE);
		scrollok(stdscr, FALSE);
		clearok(stdscr, TRUE);
	};

	bool GetIsGameOver()
	{
		return IsGameOver;
	}

	bool SetIsGameOver()
	{
		IsGameOver = true;
		return IsGameOver;
	}

	// Render top corners and ceiling of intro
	void RenderIntroCeiling()
	{
		int MapWidth = MapInstance->GetMapWidth();

		for (int i = 0; i <= MapWidth; i++)
		{
			if (i == 0) {
				Intro += "\u250C";
			} else if (i == MapWidth) {
				Intro += "\u2510";
			} else {
				Intro += "\u2500";
			}
		}

		Intro += "\n";
		return;
	}

	// Render walls and text of intro
	void RenderIntroText()
	{
		int MapHeight = MapInstance->GetMapHeight();
		int MapWidth = MapInstance->GetMapWidth();

		for (int walls = 0; walls <= MapHeight / 100; walls ++)
		{
			for (int w = 0; w <= MapWidth; w++)
			{
				if (w == 0 || w == MapWidth - 24) {
					Intro += "\u2502";
				} else if (w == MapWidth / 3) {
					Intro += "Welcome to the Snake Game";
				} else {
					Intro += " ";
				}
			}

			Intro += "\n";
		}

		return;
	}

	// Render the floor of the intro
	void RenderIntroFloor()
	{
		int MapWidth = MapInstance->GetMapWidth();


		for (int floor = 0; floor <= MapWidth; floor++)
		{
			if (floor == 0) {
				Intro += "\u2514";
			} else if (floor == MapWidth) {
				Intro += "\u2518";
			} else {
				Intro += "\u2500";
			}
		}
		return;
	}

	void SetIntro()
	{
		RenderIntroCeiling();
		RenderIntroText();
		RenderIntroFloor();
		return;
	}

	std::string PrintIntro()
	{
		return Intro;
	}

	std::string GetKeyPressed()
	{
		return KeyPressed;
	}

	void SetKeyPressed()
	{
		KeyPlayerPressed = getch();


		if (KeyPlayerPressed > -1) {
			std::cout << "KPP: " << KeyPlayerPressed << std::endl;
			switch (KeyPlayerPressed)
			{
				case UpKey:
					NewSnake.MoveUp();
					break;
				case DownKey:
					NewSnake.MoveDown();
					break;
				case LeftKey:
					NewSnake.MoveLeft();
					break;
				case RightKey:
					NewSnake.MoveRight();
					break;
				case EscapeKey:
					SetIsGameOver();
					break;

				default:
					// refresh();
					break;
			}
		} else {
			// refresh();
		}

		return;
	}

	void ReRenderMap()
	{
		getmaxyx(stdscr, row, col);
		refresh();

		MapInstance->GenerateMap(row, col);

		return;
	}

	int GetGameCounter()
	{
		return GameCounter;
	}

	void IncrementGameCounter()
	{
		GameCounter = GameCounter + 1;
		return;
	}

	void MoveSnake()
	{
		NewSnake.MoveLeft();
		return;
	}

	std::string GetGameOverText()
	{
		return GameOverText;
	}
};

#endif
