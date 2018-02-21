#include <iostream>
#include "Snake.hpp"

int main()
{
	Snake *SnakeGame = new Snake;
	SnakeGame->SetIntro();
	
	std::cout << SnakeGame->PrintIntro() << std::endl;

	return 0;
};
