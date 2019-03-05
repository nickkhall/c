#include <iostream>
#ifndef TAIL
#define TAIL

struct Tail {
	int x;
	int y;
	int index;

	Tail() {
		x = y = index = -1;
	}

	Tail(int _x, int _y) : x(_x), y(_y) {
		index = -1;
	}
};

#endif
