#include <stdlib.h>
#include <ncurses.h>

#include "headers/window.h"
#include "headers/form.h"
#include "headers/employee.h"
#include "headers/utils.h"

#define SEARCH_LABEL "Search by ID, First and/or Last name:"

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


char* print_search_form(Window* win) {
  // get length of search form label
  int label_len = strlen(SEARCH_LABEL);

  // clear screen
  clear_screen(win);

  // print search form label
  mvwprintw(win->window, win->y_max / 2, win->x_max / 2 - (label_len / 2) - 1, SEARCH_LABEL);

  // enable cursor and output
  curs_set(1);
  echo();

  // temp buffer for user input
  // (ncurses `mvngetnstr` sanitizes so no buffer overflow)
  char* key = (char*)malloc(sizeof(char) * 100);
	if (key == NULL) {
		exit(1);
	}

  // get label for search (max 100 chars)
  mvwgetnstr(win->window, win->y_max / 2, win->x_max / 2 + (label_len / 2) + 1, key, 100);

  // disable cursor and output
  curs_set(0);
  noecho();

  // clear screen again
  clear_screen(win);

	return key;
}
