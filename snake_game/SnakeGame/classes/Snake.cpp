#include "../headers/Snake.hpp"

void Snake::Init(int MapHeight, int MapWidth) {
  if (inited == TRUE) return;
  inited = true;

  TailIndex = 0;

  TailX[0] = MapWidth / 2;
  TailY[0] = MapHeight / 2;

  return;
}

// void Snake::AddTail() {
// 	int endX = GetEndX();
// 	int endY = GetEndY();
// 	int prevX = TailX[TailIndex - 2];
// 	int prevY = TailY[TailIndex - 2];
//
// 	TailIndex += 1;
//
// 	TailX[TailIndex] = endX + (endX - prevX);
// 	TailY[TailIndex] = endY + (endY - prevY);
// }

// int Snake::GetHeadX() {
// 	return TailX[0];
// }
//
// int Snake::GetHeadY() {
// 	return TailY[0];
// }
//
// int Snake::GetEndX() {
// 	return TailX[TailIndex];
// }
//
// int Snake::GetEndY() {
// 	return TailY[TailIndex];
// }

int Snake::GetTailX(int index) {
  return TailX[index];
}

int Snake::GetTailY(int index) {
  return TailY[index];
}

int Snake::GetSnakeLength() {
  return TailIndex + 1;
}

void Snake::Move() {
  int prevX = TailX[0];
  int prevY = TailY[0];

  switch(Dir)
  {
    case UP:
      TailY[0] -= 1;
      break;
    case DOWN:
      TailY[0] += 1;
      break;
    case LEFT:
      TailX[0] -= 1;
      break;
    case RIGHT:
      TailX[0] += 1;
      break;
  }

  for(int i=0;i<TailIndex - 1;i--) {
    TailX[i+1] = TailX[i];
    TailY[i+1] = TailY[i];
    if (i != 0) {
      TailX[i] = prevX;
      TailY[i] = prevY;
    }
  }
}

void Snake::MoveUp() {
  Dir = UP;
  return;
}

void Snake::MoveDown() {
  Dir = DOWN;
  return;
}

void Snake::MoveLeft() {
  Dir = LEFT;
  return;
}

void Snake::MoveRight() {
  Dir = RIGHT;
  return;
}
