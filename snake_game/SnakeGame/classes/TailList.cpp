#include "../headers/TailList.hpp"

Tail TailList::operator[] (const int &index) {
	for (auto &tail : TailsArray) {
		if (tail.index == index) {
			return tail;
		}
	}
};

int TailList::GetLength() {
	return TailsArray.size();
}

void TailList::Push(Tail &t) {
	int size = TailsArray.size();
	t.index = size;
	TailsArray.reserve(size + 1);
	TailsArray.push_back(t);
	return;
}
