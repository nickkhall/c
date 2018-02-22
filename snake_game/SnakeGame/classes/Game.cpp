#include <iostream>
#include "../headers/Game.hpp"
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"

Game::Game()
{
  IsGameOver = false;
  Intro = "";

	// Create a new Snake
	Snake NewSnake = new Snake;
	// Create new map
	Map MapInstance = new Map(NewSnake);
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
  for (int i = 0; i <= MapInstanceWidth; i++)
  {
    if (i == 0) {
      Intro += "\u250C";
    } else if (i == MapInstanceWidth) {
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
  for (int walls = 0; walls <= MapInstanceHeight / 100; walls ++)
  {
    for (int w = 0; w <= MapInstanceWidth; w++)
    {
      if (w == 0 || w == MapInstanceWidth - 24) {
        Intro += "\u2502";
      } else if (w == MapInstanceWidth / 3) {
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
  for (int floor = 0; floor <= MapInstanceWidth; floor++)
  {
    if (floor == 0) {
      Intro += "\u2514";
    } else if (floor == MapInstanceWidth) {
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
  MapInstance->GenerateMap();
  return MapInstance->PrintMap();
}
