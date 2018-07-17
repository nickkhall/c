#include <iostream>
#include "Snake.hpp"
#include "Tails.hpp"

#ifndef MAP
#define MAP

class Map
{
private:
	int MapHeight;
	int MapWidth;
	std::string MapStr;
	Snake& NewSnake;

public:
	Map(Snake& GameSnake) : NewSnake(GameSnake)
	{
		MapHeight = 21;
		MapWidth = 100;
		MapStr = "";
	}
};

#endif
