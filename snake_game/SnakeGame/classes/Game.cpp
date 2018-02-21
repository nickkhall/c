#include <iostream>
#include "../headers/Game.hpp"

Game::Game()
{
  IsGameOver = false;
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
  Intro = "\u250C\u2500\u2500\u2500\u2500\u2500\n\u2502            Welcome to the Snake Game!\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\n";
  return;
}

std::string Game::PrintIntro()
{
  return Intro;
}
