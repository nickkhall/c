#include <iostream>

class Map
{
private:
  int MapHeight;
  int MapWidth;
  std::string MapStr;

public:
  Map();

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
