#include <ncurses.h>
#include "../headers/Map.hpp"

Map::Map(Snake& GameSnake) : NewSnake(GameSnake), MapHeight {21}, MapWidth {100}, MapStr {""} {}

int Map::GetMapHeight() {
  return MapHeight;
}

int Map::GetMapWidth() {
  return MapWidth;
}

void Map::RenderMapCeiling() {
  // Render top corners and ceiling of map
  for (int i = 0; i < MapWidth; i++) {
    move(0, i);
    if (i == 0) {
      addstr("\u250C");
    } else if (i == MapWidth - 1) {
      addstr("\u2510");
    } else {
      addstr("\u2500");
    }
  }

  move(0, 3);
  addstr(" Snake Game ");
  return;
}

void Map::RenderMapContent() {
  NewSnake.Init(MapHeight, MapWidth);
  bool rendered = false;
  int snakeLength = NewSnake.GetSnakeLength();
  int tailY, tailX;

  // Render walls of map
  for (int y = 1; y < MapHeight - 1; y ++) {
    for (int x = 0; x < MapWidth; x++) {
      rendered = false;
      move(y, x);

      if (x == 0 || x == MapWidth - 1) {
        addstr("\u2502");
        rendered = true;
      }

      for (int t = 0; t < snakeLength; t++) {
        if (rendered != true) {
          tailX = NewSnake.GetTailX(t);
          tailY = NewSnake.GetTailY(t);

          if (x == tailX && y == tailY) {
            addstr("\u014C");
            rendered = true;
          }
        }
      }

      if (rendered == false) {
        addstr(" ");
      }
    }
  }

  return;
}

void Map::RenderMapFloor() {
  // Render the floor of the map
  for (int floor = 0; floor < MapWidth; floor++) {
    move(MapHeight, floor);
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

void Map::GenerateMap(int row, int col) {
  MapHeight = row;
  MapWidth = col;

  RenderMapCeiling();
  RenderMapContent();
  RenderMapFloor();
}

std::string Map::PrintMap() {
  return MapStr;
}
