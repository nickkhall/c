#include <iostream>
#include "../headers/Snake.hpp"

Snake::Snake()
{
  x = 2;
  y = 3;
}

int Snake::GetSnakeX()
{
  return x;
}

int Snake::GetSnakeY()
{
  return y;
}
