#include <iostream>
#include "Snake.hpp"

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

	int GetMapHeight()
	{
		return MapHeight;
	}

	int GetMapWidth()
	{
		return MapWidth;
	}

	void RenderMapCeiling()
	{
		// Render top corners and ceiling of map
		for (int i = 0; i <= MapWidth; i++)
		{
			if (i == 0) {
				MapStr += "\u250C";
			} else if (i == MapWidth) {
				MapStr += "\u2510";
			} else {
				MapStr += "\u2500";
			}
		}

		MapStr += "\n";
		return;
	}

	void RenderMapContent()
	{
		// Local Snake coordinates variables
		NewSnake.Init(MapHeight, MapWidth);
		int snakeX = NewSnake.GetSnakeX();
		int snakeY = NewSnake.GetSnakeY();

		// Render walls of map
		for (int y = 0; y <= MapHeight; y ++)
		{
			for (int x = 0; x <= MapWidth; x++)
			{
				if (x == 0 || x == MapWidth) {
					MapStr += "\u2502";
				} else if (x == snakeX && y == snakeY) {
					MapStr += "\u014C";
				} else {
					MapStr += " ";
				}
			}

			MapStr += "\n";
		}
		return;
	}

	void RenderMapFloor()
	{
		// Render the floor of the map
		for (int floor = 0; floor <= MapWidth; floor++)
		{
			if (floor == 0) {
				MapStr += "\u2514";
			} else if (floor == MapWidth) {
				MapStr += "\u2518";
			} else {
				MapStr += "\u2500";
			}
		}
		return;
	}

	void GenerateMap()
	{
		RenderMapCeiling();
		RenderMapContent();
		RenderMapFloor();
	}

	std::string PrintMap()
	{
		return MapStr;
	}

	bool AutoMoveSnake()
	{
		NewSnake.MoveLeft();
		return NewSnake.GetSnakeX();
	}
};

#endif
