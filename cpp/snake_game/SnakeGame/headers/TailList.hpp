#include <iostream>
#include <vector>

#include "Tails.hpp"

#ifndef TAIL_LIST
#define TAIL_LIST

class TailList { 
private:
	std::vector<Tail> TailsArray;

public:
	Tail operator[] (const int &index);

	TailList() {}

	int GetLength();
	void Push(Tail &t);
};

#endif
