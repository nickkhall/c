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
  IntroArray = ['W','e','l','c','o','m','e',' ','t','o',' ','t','h','e',' ','S','n','a','k','e',' ','G','a','m','e'];
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

void Game::SetIntro()
{
  // Intro = "u2500\u2500\u2500\u2500\u2500\n\u2502
  // Welcome to the Snake Game!\n";

  // Render top corners and ceiling of intro
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

  // Render walls and text of intro
  for (int walls = 0; walls <= MapInstanceHeight / 100; walls ++)
  {
    for (int w = 0; w <= MapInstanceHeight; w++)
    {
      if (w == 0 || w == MapInstanceHeight) {
        Intro += "\u2502";
      } else {
        for (int letter = 0; letter <= IntroArray.length; letter++)
        {
          Intro += IntroArray[letter];
        }
      }
    }
    Intro += "\n";
  }

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

std::string Game::PrintIntro()
{
  return Intro;
}
