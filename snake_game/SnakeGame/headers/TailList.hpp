#include <iostream>
#ifndef TAIL_LIST
#define TAIL_LIST

class TailList
{
private:
	int TailCount;
  Tail *TailListArray;

public:
  Tail& operator[] (const int index);
};

Tail& TailList::operator[] (const int index)
{
	return TailListArray[index];
}

#endif
