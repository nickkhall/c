#include <iostream>
#include "Snake.hpp"

int main()
{
	system("clear");
	Snake *SnakeGame = new Snake;
	SnakeGame->SetIntro();

	std::cout << SnakeGame->PrintIntro() << std::endl;
	SnakeGame->RenderMap();

	return 0;
};
