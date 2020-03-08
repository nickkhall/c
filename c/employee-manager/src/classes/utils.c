#include <stdlib.h>
#include <stdio.h>

char** allocate_strs(const int* rows, const int* cols) {
	char** t_a = NULL;
	t_a = (char**)malloc(sizeof(char*) * *rows);
	if (t_a == NULL) {
		exit(0);
	}
	
	for (int i = 0; i < *rows; i++) {
		*(t_a + i) =  (char*)malloc(sizeof(char*) * *cols);
	}

	return t_a;
};

void write_to_strs(char** s, const int* rows, const int* cols) {
	for (int r = 0; r < *rows; r++) {
		for (int c = 0; c < *cols; c++) {
			scanf("%c", (*(s + r) + c));
		}
	}
};

