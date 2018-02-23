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
const int DownKey = 100;
const int LeftKey = 115;
const int RightKey = 97;
const int EscapeKey = 27;

class Game
{
private:
	bool IsGameOver;
	std::string Intro;
	std::string KeyPressed;
	int KeyPlayerPressed;

	Snake NewSnake;
	Player NewPlayer;
	Map *MapInstance;

public:
	Game() {
		KeyPlayerPressed = 0;

		MapInstance = new Map(NewSnake);
		IsGameOver = false;
		Intro = "";
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

	std::string StartGame()
	{
		MapInstance->GenerateMap();

		// initscr();
    //
		// cbreak();
		// noecho();
		// nodelay(stdscr, TRUE);
    //
		// scrollok(stdscr, TRUE);

		return MapInstance->PrintMap();
	}

	std::string GetKeyPressed()
	{
		return KeyPressed;
	}

	void SetKeyPressed()
	{
		while (IsGameOver != true)
		{
			if (getch()) {
				KeyPlayerPressed = getch();

				switch (KeyPlayerPressed)
				{
					case UpKey:
						if(KeyPlayerPressed == UpKey)
						{
							// NewSnake.MoveUp();
							std::cout << "We have a match!" << std::endl;
							std::cout << "KeyPlayerPressed: " << KeyPlayerPressed << std::endl;
						}
						break;
					case DownKey:
						if(KeyPlayerPressed == DownKey)
						{
							// NewSnake.MoveDown();
							std::cout << "We have a match!" << std::endl;
							std::cout << "KeyPlayerPressed: " << KeyPlayerPressed << std::endl;
						}
						break;
					case LeftKey:
						if(KeyPlayerPressed == LeftKey)
						{
							// NewSnake.MoveLeft();
							std::cout << "We have a match!" << std::endl;
							std::cout << "KeyPlayerPressed: " << KeyPlayerPressed << std::endl;
						}
						break;
					case RightKey:
						if(KeyPlayerPressed == RightKey)
						{
							// NewSnake.MoveRight();
							std::cout << "We have a match!" << std::endl;
							std::cout << "KeyPlayerPressed: " << KeyPlayerPressed << std::endl;
						}
						break;
					case EscapeKey:
						SetIsGameOver();
						break;

					default:
						refresh();
						break;
				}
			} else {
				refresh();
			}
		}

		return;
	}

};

#endif
