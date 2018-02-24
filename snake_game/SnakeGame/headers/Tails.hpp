#include <iostream>
#ifndef TAIL
#define TAIL

class Tail
{
private:
	int x;
	int y;

public:
	Tail() {
		x = y = -1;
		return;
	}

	Tail(int _x, int _y)
	{
		x = _x;
		y = _y;
		return;
	}

	void Init(int _x, int _y) {
		x = _x;
		y = _y;
		return;
	}

	int GetTailX()
	{
		return x;
	}

	int GetTailY()
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
