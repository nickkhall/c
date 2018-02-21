#include <iostream>

class Game
{
private:
	bool IsGameOver;

protected:
	const std::string Intro;

public:
	Game();

	// Setters
	void SetIntro();
	bool SetIsGameOver();

	// Getters
	bool GetIsGameOver();
	std::string PrintIntro();
};
