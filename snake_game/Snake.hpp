#include <iostream>

class Snake
{
private:
	bool IsGameOver;
	int MapHeight;
	int MapWidth;
	std::string Intro;

public:
	Snake();

	bool GetGameStatus();

	// Getters
	std::string PrintIntro();

	// Setters
	std::string SetIntro();
	void RenderMap();
};
