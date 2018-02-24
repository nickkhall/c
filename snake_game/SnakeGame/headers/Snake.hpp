#include <iostream>

#include "Tails.hpp"

#ifndef SNAKE
#define SNAKE

// @TODO: Refactor to use TailList

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake
{
private:
	Direction Dir;
	int TailX[100], TailY[100];
	int TailIndex;
	bool inited;

public:
	Snake() {
		inited = FALSE;
		TailIndex = -1;
		Dir = LEFT;
	};

	void Init(int MapHeight, int MapWidth)
	{
		if (inited == TRUE) return;
		inited = true;

		TailIndex = 0;

		TailX[0] = MapWidth / 2;
		TailY[0] = MapHeight / 2;

		return;
	}

	// void AddTail()
	// {
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

	// int GetHeadX()
	// {
	// 	return TailX[0];
	// }
  //
	// int GetHeadY()
	// {
	// 	return TailY[0];
	// }
  //
	// int GetEndX()
	// {
	// 	return TailX[TailIndex];
	// }
  //
	// int GetEndY()
	// {
	// 	return TailY[TailIndex];
	// }

	int GetTailX(int index)
	{
		return TailX[index];
	}

	int GetTailY(int index)
	{
		return TailY[index];
	}

	int GetSnakeLength()
	{
		return TailIndex + 1;
	}

	void Move() {
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

	void MoveUp()
	{
		Dir = UP;
		return;
	}

	void MoveDown()
	{
		Dir = DOWN;
		return;
	}

	void MoveLeft()
	{
		Dir = LEFT;
		return;
	}

	void MoveRight()
	{
		Dir = RIGHT;
		return;
	}
};

#endif
