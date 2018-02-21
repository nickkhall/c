#include <iostream>
#include <array>

class Game
{
private:
	bool IsGameOver;
	std::string Intro;

public:
	Game();

	// Setters
	void SetIntro();
	void RenderMapCeiling();
	void RenderMapWalls();
	void RenderMapFloor();
	bool SetIsGameOver();

	// Getters
	bool GetIsGameOver();
	std::string PrintIntro();
};
