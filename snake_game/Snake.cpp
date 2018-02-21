#include <iostream>
#include "Snake.hpp"

Snake::Snake()
{
  IsGameOver = false;
  MapHeight = 20;
  MapWidth = 20;
}

bool Snake::GetGameStatus()
{
  return IsGameOver;
}

std::string Snake::SetIntro()
{
  Intro = "--------------------------\nWelcome to the Snake Game!\n--------------------------\n";
  return Intro;
}

std::string Snake::PrintIntro()
{
  return Intro;
}
