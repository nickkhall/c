#include <stdlib.h>
#include <stdio.h>

char** allocate_strs(const int *rows, const int *cols) {
	char **t_a = NULL;
	t_a = (char**)malloc(sizeof(char*) * *rows);
	if (t_a == NULL) {
		exit(0);
	}
	
	for (int i = 0; i < *rows; i++) {
		*(t_a + i) =  (char*)malloc(sizeof(char*) * *cols);
	}

	return t_a;
};

void write_to_strs(char **s, const int *rows, const int *cols) {
	for (int r = 0; r < *rows; r++) {
		for (int c = 0; c < *cols; c++) {
			scanf("%c", (*(s + r) + c));
		}
	}
};

void write_to_file(const char** labels, char **string, const int *size) {
	// create file pointer to data/employees.txt
	FILE *file = fopen("data/employees.txt", "w+");

	// add new line to separate entries
	fputs("\n---------------------------------------------------------------\n", file);
	
	for (int i = 0; i < *size; i++) {
		// add data entry
		fputs(*(labels + i), file);
		fputs(": ", file);
		fputs(*(string + i), file);
		if (i < *size) {
			fputs(",\n", file);
		}
	}

	// add new line to separate entries
	fputs("\n---------------------------------------------------------------\n", file);

	// close file stream
	fclose(file);
	
	// free up file pointer memory
	free(file);
};

