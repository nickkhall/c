#include <iostream>

#include "Tails.hpp"

#ifndef SNAKE
#define SNAKE

class Snake
{
private:
	Tail *TailsArray;
	int TailCount;
	bool inited;

public:
	Snake() {
		inited = FALSE;
		TailCount = 1;
	};

	void Init(int MapHeight, int MapWidth)
	{
		if (inited == TRUE) return;
		inited = true;

		int x = MapWidth / 2;
		int y = MapHeight / 2;

		TailsArray = new Tail[1];
		TailsArray[0].Init(x,y);

		return;
	}

	void AddTail(int newX, int newY)
	{
		TailCount = TailCount + 1;
		Tail TempTailsArray = *TailsArray;
		delete [] TailsArray;

		TailsArray = new Tail[TailCount];

		int tempX, tempY;

		for (int i = 0; i < TailCount; i++)
		{
			tempX = TempTailsArray[i].GetTailX();
			tempY = TempTailsArray[i].GetTailY();
			TailsArray[i].Init(tempX, tempY);
			delete TempTailsArray[i];
		}

		TailsArray[TailCount].Init(newX, newY);

		delete [] TempTailsArray;
	}

	Tail GetSnakeTails()
	{
		return TailsArray;
	}

	int GetSnakeLength()
	{
		return TailCount;
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
