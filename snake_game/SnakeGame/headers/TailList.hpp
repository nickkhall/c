#include <iostream>
#include <vector>

#include "Tails.hpp"

#ifndef TAIL_LIST
#define TAIL_LIST

class TailList
{
private:
	std::vector<Tail> TailsArray;

public:
	Tail operator[] (const int &index);

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

int TailList::GetLength()
{
	return TailsArray.size();
}

void Push(Tail &t)
{
	int size = TailsArray.size();
	t.index = size;
	TailsArray.reserve(size + 1);
	TailsArray.push_back(t);
	return;
}

#endif
