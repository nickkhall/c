#include <iostream>
#include "../headers/Game.hpp"
#include "../headers/Map.hpp"

Map *MapInstance = new Map;
int MapInstanceHeight = MapInstance->GetMapHeight();
int MapInstanceWidth = MapInstance->GetMapWidth();

Game::Game()
{
  IsGameOver = false;
  Intro = "";
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
void Game::RenderMapCeiling()
{
  for (int i = 0; i <= MapInstanceWidth; i++)
  {
    if (i == 0) {
      Intro += "\u250C";
    } else if (i == MapInstanceWidth) {
      Intro += "\u2511";
    } else {
      Intro += "\u2500";
    }
  }

  Intro += "\n";
  return;
}

void Game::RenderMapWalls()
{
  // Render walls and text of intro
  for (int walls = 0; walls <= MapInstanceHeight / 100; walls ++)
  {
    for (int w = 0; w <= MapInstanceHeight; w++)
    {
      if (w == 0 || w == MapInstanceHeight - 24) {
        Intro += "\u2502";
      } else if (w == (MapInstanceHeight / 2) / 2) {
        Intro += "Welcome to the Snake Game";
      } else {
        Intro += " ";
      }
    }

    Intro += "\n";
  }
  return;
}

void Game::RenderMapFloor()
{
  // Render the floor of the intro
  for (int floor = 0; floor <= MapInstanceWidth; floor++)
  {
    if (floor == 0) {
      Intro += "\u2514";
    } else if (floor == MapInstanceWidth) {
      Intro += "\u2518";
    } else {
      Intro += "\u2501";
    }
  }
  return;
}

void Game::SetIntro()
{
  RenderMapCeiling();
  RenderMapWalls();
  RenderMapFloor();
}

std::string Game::PrintIntro()
{
  return Intro;
}
