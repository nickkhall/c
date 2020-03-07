#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../headers/uuid.h"

char* generate_uuid() {
	int min = 0;
	int max = 30;
	char* uid = NULL;
	uid = (char*)malloc(sizeof(max));

	char chars[35] = {
		'0', '1', '2', '3',
		'p', 'b', 'k', 'd',
		'v', 'w', 'x', 'y',
		'4', '5', 'z',
		'e', 'f', 'g', 'h',
		'r', 's', 't', 'u',
		'i', 'j', 'c', 'l',
		'8', '9', 'o', 'a',
		'm', 'n', '6', '7',
	};

	// Set random seed
	srand(time(0));

	for (int i = 0; i < max; i++) {
		int num = (rand() % (min - max + 1)) + min;

		if (i != 0 && (i+1) % 5 == 0) uid[i] = '-';
		else uid[i] = chars[num];
	};

	return uid;
};

