#include <iostream>
#include <array>
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"

#ifndef GAME
#define GAME

class Game
{
private:
	bool IsGameOver;
	std::string Intro;
	Snake NewSnake;
	Map *MapInstance;

public:
	Game() {
		MapInstance = new Map(NewSnake);
	  IsGameOver = false;
	  Intro = "";
	};

	bool SetIsGameOver()
	{
	  IsGameOver = true;
	  return IsGameOver;
	}

	bool GetIsGameOver()
	{
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
	  return MapInstance->PrintMap();
	}
};

#endif
