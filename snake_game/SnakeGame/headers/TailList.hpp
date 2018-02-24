#include <iostream>
#ifndef TAIL_LIST
#define TAIL_LIST

class TailList
{
private:
	std::vector(Tail) TailsArray;

public:
	int[] operator[] (const int &index);

	TailList() {}
};

TailList::operator[] (const int &index)
{
	for (auto &tail : TailsArray)
	{
		if (tail.index == index)
		{
			return tail;
		}
	}
};

// @TODO: Create static method for
	// - Get length
	// - Push

#endif
