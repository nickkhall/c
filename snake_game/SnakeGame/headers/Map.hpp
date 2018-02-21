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
  int GetMapHeight();
  int GetMapWidth();
};
