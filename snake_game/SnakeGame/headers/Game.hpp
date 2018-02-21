#include <iostream>

class Game
{
private:
	bool IsGameOver;
	std::string Intro;


public:
	Game();

	// Setters
	void SetIntro();
	bool SetIsGameOver();

	// Getters
	bool GetIsGameOver();
	std::string PrintIntro();
};
