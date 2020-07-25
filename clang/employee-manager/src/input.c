#include <stdlib.h>
#include <ncurses.h>

// #include "headers/libpq-fe.h"
#include "headers/window.h"
#include "headers/input.h"
#include "headers/utils.h"

char** create(Window *window, const char** form_labels, const int *num_of_fields) {
  // enable cursor
  curs_set(1);

  // print user input to screen
  echo();
  
  char** form_data = NULL;
  form_data = malloc(sizeof(char*) * *num_of_fields);

  // iterate over form labels (size of form)
  for (int i = 0; i < *num_of_fields; i++) {
    // erase / refresh screen
    refresh();
    wrefresh(window->window);

    // create local variable for storing user input
    char* temp_data = NULL;
    temp_data = malloc(sizeof(char) * 50);

    int str_length = (int)strlen(*(form_labels + i));

    // move cursor and print form labels
    mvwprintw(
      window->window,
      (window->y_max / 2),
      (window->x_max / 2) - (str_length / 2),
      *(form_labels + i)
    );

    // erase / refresh screen again
    clear();
    refresh();
    wrefresh(window->window);

    // move cursor to after form_label for user input    
    mvwgetnstr(window->window, window->y_max / 2, window->x_max / 2 + (str_length / 2) + 1, temp_data, 50);

    // after user input, push data onto form_data array
    *(form_data + i) = temp_data;
  }

  // erase / refresh screen
  werase(window->window);
  refresh();
  wrefresh(window->window);

  // disable cursor
  curs_set(0);

  return form_data;
};

char* get_search_input(Window* win) {
  // enable cursor and output
  curs_set(1);
  echo();

  // temp buffer for user input
  // (ncurses `mvngetnstr` sanitizes so no buffer overflow)
  char* buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL) {
		exit(1);
	}

  int label_len = strlen(SEARCH_LABEL);
  // get label for search (max 100 chars)
  mvwgetnstr(win->window, win->y_max / 2, win->x_max / 2 + (label_len / 2) + 1, buffer, BUFFER_SIZE);

  // disable cursor and output
  curs_set(0);
  noecho();

  // clear screen again
  clear_screen(win);

	return buffer;
}

void* convert_query_to_data(PGresult* res, const int* rows, const int* cols) {
	// @TODO: separate this logic into function if successful
	char*** query_data;
	query_data = calloc(*rows, sizeof(char**));

	if (query_data == NULL) {
		system("reset");
		printf("failure to allocate heap memory for convert_query_to_data()");
		PQclear(res);
		
		void* null_pointer = NULL;
		return null_pointer;
	}

	for (int r = 0; r < *rows; r++) {
		*(query_data + r) = calloc(*cols, sizeof(char*));

		for (int c = 0; c < *cols; c++) {	
			*(*(query_data + r) + c) = calloc(MAX_STR_SIZE, (sizeof(char)));

			char* value = PQgetvalue(res, r, c);

			*(*(*(query_data + r) + c)) = *value;
		}
	}

	return query_data;
}
