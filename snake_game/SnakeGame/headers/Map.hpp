#include <iostream>

class Map
{
private:
  int MapHeight;
  int MapWidth;

public:
  Map();

  // Setters
  void RenderMap();
  int GetMapHeight();
  int GetMapWidth();
};
