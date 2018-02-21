#include <iostream>
#include <array>

class Game
{
private:
	bool IsGameOver;
	std::string Intro;
	array IntroArray;

public:
	Game();

	// Setters
	void SetIntro();
	bool SetIsGameOver();

	// Getters
	bool GetIsGameOver();
	std::string PrintIntro();
};
