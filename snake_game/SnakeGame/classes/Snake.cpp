#include <iostream>
#include "../headers/Snake.hpp"
#ifndef SNAKE_CLASS
#define SNAKE_CLASS

Snake::Snake()
{
  inited = false;
  return;
}

void Snake::Init(int MapHeight, int MapWidth)
{
  if (inited == true) return;
  inited = true;
  x = MapWidth / 2;
  y = MapHeight / 2;
  return;
}

int Snake::GetSnakeX()
{
  return x;
}

int Snake::GetSnakeY()
{
  return y;
}

void Snake::MoveUp()
{
  y = y - 1;
  return;
}

void Snake::MoveDown()
{
  y = y + 1;
  return;
}

void Snake::MoveLeft()
{
  x = x - 1;
  return;
}

void Snake::MoveRight()
{
  x = x + 1;
  return;
}

#endif
