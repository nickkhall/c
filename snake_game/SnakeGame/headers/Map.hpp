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
		for (int i = 0; i < MapWidth; i++)
		{
			move(0, i);
			// refresh();
			if (i == 0) {
				addstr("\u250C");
			} else if (i == MapWidth - 1) {
				addstr("\u2510");
			} else {
				addstr("\u2500");
			}
		}
		return;
	}

	void RenderMapContent()
	{
		// Local Snake coordinates variables
		NewSnake.Init(MapHeight, MapWidth);
		int snakeX = NewSnake.GetSnakeX();
		int snakeY = NewSnake.GetSnakeY();

		// Render walls of map
		for (int y = 1; y < MapHeight - 1; y ++)
		{
			for (int x = 0; x < MapWidth; x++)
			{
				move(y, x);
				// refresh();
				if (x == 0 || x == MapWidth - 1) {
					addstr("\u2502");
				} else if (x == snakeX && y == snakeY) {
					addstr("\u014C");
				} else {
					addstr(" ");
				}
			}
		}
		return;
	}

	void RenderMapFloor()
	{
		// Render the floor of the map
		for (int floor = 0; floor < MapWidth; floor++)
		{
			move(MapHeight, floor);
			// refresh();
			if (floor == 0) {
				addstr("\u2514");
			} else if (floor == MapWidth - 1) {
				addstr("\u2518");
			} else {
				addstr("\u2500");
			}
		}
		return;
	}

	void GenerateMap(int row, int col)
	{
		MapHeight = row;
		MapWidth = col;

		RenderMapCeiling();
		RenderMapContent();
		RenderMapFloor();
	}

	std::string PrintMap()
	{
		// std::cout << MapHeight << std::endl;
		// std::cout << MapWidth << std::endl;
		return MapStr;
	}

	bool AutoMoveSnake()
	{
		NewSnake.MoveLeft();
		return NewSnake.GetSnakeX();
	}
};

#endif
