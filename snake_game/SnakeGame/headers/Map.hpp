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

public:
  Map(Snake Snake);

  // Setters
  void GenerateMap();
  void RenderMapCeiling();
  void RenderMapContent();
  void RenderMapFloor();

  // Getters
  std::string PrintMap();
  int GetMapHeight();
  int GetMapWidth();
};

#endif
