#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LINE_SIZE 100

/**
 * Allocates a sum of memory for a string array.
 * @param {int*} rows The number of strings in the string array to be alloted.
 * @param {int*} cols The number of strings in the nested string array.
 * @return {char**} A pointer to the string array.
 **/
char** allocate_strs(const int *rows, const int *cols) {
	// declare return pointer to null
	char **t_a = NULL;
	// allocate the appropriate memory
	t_a = (char**)malloc(sizeof(char*) * *rows);
	// if there was a problem with allocating memory
	if (t_a == NULL) {
		// exit
		exit(0);
	}
	
	// iterate over allocated memory
	for (int i = 0; i < *rows; i++) {
		// write data to allocated memory
		*(t_a + i) =  (char*)malloc(sizeof(char*) * *cols);
	}

	// return pointer
	return t_a;
};

/**
 * Writes data to a pre-allocated strings array.
 * @param {char**} s The string array.
 * @param {int*} rows The number of strings in the string array to be alloted.
 * @param {int*} cols The number of strings in the nested string array.
 * @return {void}
 **/
void write_to_strs(char **s, const int *rows, const int *cols) {
	for (int r = 0; r < *rows; r++) {
		for (int c = 0; c < *cols; c++) {
			scanf("%c", (*(s + r) + c));
		}
	}
};

/**
 * Writes a series of strings to a file.
 * @param {char**} labels The labels / description of the data.
 * @param {char**} string The string / data to write to the file.
 * @param {int*} size The size of the strings array.
 * @return {void}
 **/
void write_to_file(const char** labels, char **string, const int *size) {
	// create file pointer to data file
	FILE *file = fopen("data/employees.txt", "a");

	// add new line to separate entries
	if (feof(file)) fputs("---------------------------------------------------------------\n", file);
	else fputs("\n---------------------------------------------------------------\n", file);
	
	for (int i = 0; i < *size; i++) {
		// add label
		fputs(*(labels + i), file);
		// add data
		fputs(*(string + i), file);
		// if not end of data
		if (i < *size - 1) {
			// input comma with new line
			fputs(",\n", file);
		}
	}

	// add new line to separate entries
	fputs("\n---------------------------------------------------------------\n", file);

	// close file stream
	fclose(file);
};

/**
 * Reads and searches a file for a match.
 * @param {FILE*} file A pointer to the file.
 * @param {char*} The key word to search by
 * @return {char**} A pointer to the sectioned off data
 **/
void* search_from_file(char *key, char *value, const char **labels, const size_t labels_size) {
	// open && create pointer to file
	FILE *file = fopen("data/employees.txt", "r");

	// if there is a problem opening file
	if (file == NULL) {
		void *return_pointer = NULL;

		return return_pointer;
	}; 

	char *line = NULL;
	line = (char*)malloc(sizeof(char) * LINE_SIZE);

	while(fgets(line, LINE_SIZE, file) != NULL) {
		long int is_match = 0;

		for (int lc = 0; lc < LINE_SIZE; lc++) {
			char *next_chars = NULL;
			next_chars = (char*)malloc(sizeof(char) * (sizeof(key) / sizeof(*key)));

			for (int x = 0; x < (sizeof(key) / sizeof(*key)); x++) {
				*(next_chars + x) = *(line + (lc + x));
			}

			if (strcmp(next_chars, key) == 0) is_match = ftell(file);
			
			if (is_match) {
				int x = 0;
			}

			free(next_chars);
		}
	}


	// close file
	fclose(file);

	// free up line memory
	free(line);
	
	return 0;
};
