#include <iostream>
#include <array>
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"

#ifndef GAME
#define GAME

class Game
{
private:
	bool IsGameOver;
	std::string Intro;
	Snake NewSnake;
	Map MapInstance(Snake NewSnake);

public:
	Game();
	Game(Snake &MainSnake, Map &MainMap);

	// Setters
	void SetIntro();
	void RenderIntroCeiling();
	void RenderIntroText();
	void RenderIntroFloor();

	bool SetIsGameOver();

	// Getters
	bool GetIsGameOver();
	std::string PrintIntro();
	std::string StartGame();
};

#endif
