#include <iostream>

#include "Tails.hpp"

#ifndef SNAKE
#define SNAKE

// @TODO: Refactor to use TailList

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
private:
	Direction Dir;
	int TailX[100], TailY[100];
	int TailIndex;
	bool inited;

public:
	Snake();

	void Init(int MapHeight, int MapWidth);
	int GetTailX(int index);
	int GetTailY(int index);
	int GetSnakeLength();
	void Move();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

#endif
