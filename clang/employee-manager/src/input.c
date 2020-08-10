#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <form.h>

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

char** input_get_form_input(Window* win, char** data) {
  int y_offset = win->y_max / 11;
  int x_offset = (win->x_max / 7) + 13;
  int current_offset = y_offset;

  WINDOW* form_win = newwin(0,0,0,0);
  FIELD* fields[11];
  FORM*  create_form;
  int key; 
  int rows;
  int cols;

  for (int f = 0; f < 11; f++) {
    if (f == 10) {
      *(fields + f) = NULL;
      break;
    }
    // allocate memory for data array
    *(data + f) = (char*) malloc(sizeof(char) * 101);
    if (!*(data + f) || *(data + f) == NULL) {
      printf("ERROR:: Failed to allocate memory for data in input_get_form_input\n");
      free(data);
      exit(1);
    }

    // create fields
    *(fields + f) = new_field(1, 50,        // height and width
                              (f * y_offset),
                              x_offset,
                              0, 0);        // render entire field and idk anymore

    field_opts_off(*(fields + f), O_AUTOSKIP);
    // set field type with field validation
    set_field_back(*(fields + f), A_UNDERLINE);
    // disable ability to move to next field at filled buffer
    // if (f == 0) field_opts_off(*(fields + f), O_ACTIVE);
  }
    

  // set_field_type(*(fields + f), TYPE_ALPHA);

  // create a new form and post it
  create_form = new_form(fields);

  scale_form(create_form, &rows, &cols);

  // set form window and sub-window
  set_form_win(create_form, form_win);
  set_form_sub(create_form, derwin(win->window,
                                  rows, cols,
                                  y_offset, x_offset));

  // post form
  post_form(create_form);

  // refresh screen
  window_refresh(win);

  // disable output
  noecho();
  // enable cursor
  curs_set(1);

  // start at first input field
  form_driver(create_form, REQ_FIRST_FIELD);

  // monitor user input
  while((key = wgetch(win->window)) != KEY_F(1)) {
    switch(key) {
      case 9:
      case KEY_DOWN:
          // go to next field
          form_driver(create_form, REQ_NEXT_FIELD);
          // go to end of the current buffer
          form_driver(create_form, REQ_END_LINE);
          break;
        case KEY_UP:
          // go to previous field
          form_driver(create_form, REQ_PREV_FIELD);
          // go to end of the current buffer
          form_driver(create_form, REQ_END_LINE);
          break;
        case KEY_BACKSPACE:
          // delete the previous character
          form_driver(create_form, REQ_DEL_PREV);
          // go to end of the current buffer
          form_driver(create_form, REQ_END_LINE);
          break;
        // space character
        case 32:          
          // inserts blank character at current position
          form_driver(create_form, REQ_INS_CHAR);
          // go to next character
          form_driver(create_form, REQ_NEXT_CHAR); 
          break;
        default:
          // print character
          form_driver(create_form, key);
          //form_driver(create_form, );
          break;
      }

      //form_driver(create_form, REQ_VALIDATION);
      window_refresh(win);
    }

  /* Un post form and free the memory */
  unpost_form(create_form);
  free_form(create_form);
  for (int f = 0; f < 11; f++) {
    free_field(*(fields + f));
  }

  // disable output and hide cursor
  curs_set(0);
}

