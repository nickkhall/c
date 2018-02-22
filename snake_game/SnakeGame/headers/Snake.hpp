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
	Snake();

	void Init(int MapHeight, int MapWidth);
	int GetSnakeX();
	int GetSnakeY();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

#endif
