#include <iostream>
#include "../headers/Map.hpp"

Map::Map()
{
  MapHeight = 50;
  MapWidth = 50;
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

void Map::GenerateMap()
{
  // MapStr = "u2500\u2500\u2500\u2500\u2500\n\u2502
  // Welcome to the Snake Game!\n";

  // Render top corners and ceiling of map
  for (int i = 0; i <= MapWidth; i++)
  {
    if (i == 0) {
      MapStr += "\u250C";
    } else if (i == MapWidth) {
      MapStr += "\u2511";
    } else {
      MapStr += "\u2500";
    }
  }

  MapStr += "\n";

  // Render walls of map
  for (int walls = 0; walls <= MapHeight / 3; walls ++)
  {
    for (int w = 0; w <= MapHeight; w++)
    {
      if (w == 0 || w == MapHeight) {
        MapStr += "\u2502";
      } else {
        MapStr += " ";
      }
    }
    MapStr += "\n";
  }

  // Render the floor of the map
  for (int floor = 0; floor <= MapWidth; floor++)
  {
    if (floor == 0) {
      MapStr += "\u2514";
    } else if (floor == MapWidth) {
      MapStr += "\u2518";
    } else {
      MapStr += "\u2501";
    }
  }
  return;
}
