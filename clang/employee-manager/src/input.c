#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "headers/input.h"
#include "headers/window.h"

char** input_create(Window* win, const char** form_labels, const int* num_of_fields) {
  // enable cursor
  curs_set(1);

  // print user input to screen
  echo();
  
  char** form_data = NULL;
  form_data = malloc(sizeof(char*) * *num_of_fields);

  // iterate over form labels (size of form)
  for (int i = 0; i < *num_of_fields; i++) {
    // erase / refresh screen
    window_clear(win);

    // create local variable for storing user input
    char* temp_data = NULL;
    temp_data = malloc(sizeof(char) * 50);

    int str_length = (int)strlen(*(form_labels + i));

    // move cursor and print form labels
    mvwprintw(
      win->window,
      (win->y_max / 2),
      (win->x_max / 2) - (str_length / 2),
      *(form_labels + i)
    );

    // erase / refresh screen again
    window_refresh(win);

    // move cursor to after form_label for user input    
    mvwgetnstr(
        win->window,
        win->y_max / 2,
        win->x_max / 2 + (str_length / 2) + 1,
        temp_data,
        50);

    // after user input, push data onto form_data array
    *(form_data + i) = temp_data;
  }

  // erase / refresh screen
  window_refresh(win);

  // disable cursor
  curs_set(0);

  return form_data;
};

char* input_get_search_input(Window* win) {
  // enable cursor and output
  curs_set(1);
  echo();

  // temp buffer for user input
  // (ncurses `mvngetnstr` sanitizes so no buffer overflow)
  char* buffer = (char*) malloc(sizeof(char) * 101);
  if (!buffer || buffer == NULL) {
    printf("ERROR:: Failed to alloctate memory for buffer in input_get_search_input\n");
    free((char*) buffer);
    exit(1);
  }

  // get label for search (max 100 chars)
  mvwgetnstr(
      win->window,
      win->y_max / 2,
      win->x_max / 2 + (33 / 2) + 3,
      buffer,
      101
    );

  // disable cursor and output
  curs_set(0);
  noecho();

  // clear screen again
  window_clear(win);

  return buffer;
}

