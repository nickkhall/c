#include <iostream>
#ifndef SNAKE
#define SNAKE

class Snake
{
private:
	int x;
	int y;
	bool inited;

public:
	Snake() {
		inited = FALSE;
	};

	void Init(int MapHeight, int MapWidth)
	{
		if (inited == TRUE) return;
		inited = true;

		x = MapWidth / 2;
		y = MapHeight / 2;
		return;
	}

	int GetSnakeX()
	{
		return x;
	}

	int GetSnakeY()
	{
		return y;
	}

	void MoveUp()
	{
		y = y - 1;
		return;
	}

	void MoveDown()
	{
		y = y + 1;
		return;
	}

	void MoveLeft()
	{
		x = x - 1;
		return;
	}

	void MoveRight()
	{
		x = x + 1;
		return;
	}
};

#endif
