#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
int search_from_file(char* key, char* value, const char** labels, const size_t labels_size) {
	// open && create pointer to file
	FILE *file = fopen("data/employees.txt", "r");

	// if there is a problem opening file
	if (file == NULL) return 1; 

	char* line;

	while(fgets(line, 100, file) != NULL) {
		sscanf(line, "%s", file);

		if (strcmp(key, value)) {
			
		}
	}

	// search file for key word
	fscanf(file, "%s", key);

	// get current postion in file
	long int cur_index = ftell(file);

	// @TODO finish finding current spot and print blob of data until user
	// presses "Escape", "Enter" or "Spacebar"

	// close file
	fclose(file);
	
	return 0;
};
