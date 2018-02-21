#include <iostream>
#include "../headers/Snake.hpp"

Snake::Snake()
{
  IsGameOver = false;
  MapHeight = 50;
  MapWidth = 50;
}

bool Snake::GetGameStatus()
{
  return IsGameOver;
}

std::string Snake::SetIntro()
{
  Intro = "\u250C\u2500\u2500\u2500\u2500\u2500\n\u2502            Welcome to the Snake Game!\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\n";
  return Intro;
}

std::string Snake::PrintIntro()
{
  return Intro;
}

void Snake::RenderMap()
{
  // Output map ceiling
  for (int ceiling = 0; ceiling <= MapWidth; ceiling++)
  {
    if (ceiling == 0) {
      std::cout << "\u250C";
    } else if (ceiling == MapWidth) {
      std::cout << "\u2510";
    } else {
      std::cout << "\u2500";
    }

  }

  std::cout << std::endl;

  // Output map walls
  for (int walls = 0; walls <= MapHeight / 2.5; walls++)
  {
    for (int w = 0; w <= MapHeight; w++)
    {
      if (w == 0 || w == MapHeight)
      {
        std::cout << "\u2502";
        if (w == MapHeight) {
          std::cout << std::endl;
        }
      } else
      {
        std::cout << " ";
      }
    }
  }

  // Output map floor
  for (int floor = 0; floor <= MapWidth; floor++)
  {
    if (floor == 0) {
      std::cout << "\u2514";
    } else if (floor == MapWidth) {
      std::cout << "\u2518";
    } else {
      std::cout << "\u2500";
    }
  }
}
