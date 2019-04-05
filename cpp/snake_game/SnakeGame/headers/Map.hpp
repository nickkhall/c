#include <iostream>
#include "Snake.hpp"
#include "Tails.hpp"

#ifndef MAP
#define MAP

class Map {
private:
	int MapHeight;
	int MapWidth;
	std::string MapStr;
	Snake& NewSnake;

public:
	Map(Snake& GameSnake);

	int GetMapHeight();
	int GetMapWidth();
	void RenderMapCeiling();
	void RenderMapContent();
	void RenderMapFloor();
	void GenerateMap(int row, int col);
	std::string PrintMap();
};

#endif
