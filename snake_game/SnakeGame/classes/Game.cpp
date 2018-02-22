#include <iostream>
#include "../headers/Game.hpp"
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"

Game::Game()
{
	return;
}

Game::Game(Snake &MainSnake, Map &MainMap)
{
  IsGameOver = false;
  Intro = "";

	// Create a new Snake
	NewSnake = MainSnake;
	MapInstance = MainMap;
}

bool Game::SetIsGameOver()
{
  IsGameOver = true;
  return IsGameOver;
}

bool Game::GetIsGameOver()
{
  return IsGameOver;
}

// Render top corners and ceiling of intro
void Game::RenderIntroCeiling()
{
	int MapWidth = MapInstance.GetMapWidth();

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
void Game::RenderIntroText()
{
	int MapHeight = MapInstance.GetMapHeight();
	int MapWidth = MapInstance.GetMapWidth();

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
void Game::RenderIntroFloor()
{
	int MapWidth = MapInstance.GetMapWidth();


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

void Game::SetIntro()
{
  RenderIntroCeiling();
  RenderIntroText();
  RenderIntroFloor();
  return;
}

std::string Game::PrintIntro()
{
  return Intro;
}

std::string Game::StartGame()
{
  MapInstance.GenerateMap();
  return MapInstance.PrintMap();
}
