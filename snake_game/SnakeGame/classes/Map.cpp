#include <iostream>
#include "../headers/Map.hpp"
#include "../headers/Snake.hpp"

Map::Map(Snake Snake)
{
  MapHeight = 21;
  MapWidth = 100;
  MapStr = "";
}

int Map::GetMapHeight()
{
  return MapHeight;
}

int Map::GetMapWidth()
{
  return MapWidth;
}

void Map::RenderMapCeiling()
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

void Map::RenderMapContent()
{
	// Local Snake coordinates variables
	Snake->Init(MapHeight, MapWidth);
	int snakeX = Snake->GetSnakeX();
	int snakeY = Snake->GetSnakeY();

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

void Map::RenderMapFloor()
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

void Map::GenerateMap()
{
  RenderMapCeiling();
  RenderMapContent();
  RenderMapFloor();
}

std::string Map::PrintMap()
{
  return MapStr;
}
