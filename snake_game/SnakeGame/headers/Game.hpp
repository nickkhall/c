#include <iostream>
#include <array>
#ifndef GAME
#define GAME

class Game
{
private:
	bool IsGameOver;
	std::string Intro;

public:
	Game();

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
