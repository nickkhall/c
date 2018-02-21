#include <iostream>
#include "Snake.hpp"

Snake::Snake()
{
  IsGameOver = false;
}

bool Snake::GetGameStatus()
{
  return IsGameOver;
}
