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
};

#endif
