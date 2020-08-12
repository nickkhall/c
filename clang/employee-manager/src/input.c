#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <form.h>
#include <ctype.h>

#include "headers/input.h"
#include "headers/window.h"

char* trim_whitespaces(char *str){
	char *end;

	// trim leading space
	while(isspace(*str))
		str++;

	if(*str == 0) // all spaces?
		return str;

	// trim trailing space
	end = str + strnlen(str, 101) - 1;

	while(end > str && isspace(*end))
		end--;

	// write new null terminator
	*(end + 1) = '\0';

	return str;
}

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


void handle_input(Window* win, FORM* create_form, int* key) { 
  while((*key = wgetch(win->window)) != 10) {
    switch(*key) {
      // tab character
      case 9:
      case KEY_DOWN:
          // go to next field
          form_driver(create_form, REQ_NEXT_FIELD);
          // go to end of the current buffer
          //form_driver(create_form, REQ_END_LINE);
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
          form_driver(create_form, *key);
          break;
    }

    form_driver(create_form, REQ_VALIDATION);
    window_refresh(win);
  }
}



char** input_get_form_input(Window* win, char** data) {
  int current_field_num = 0;
  int y_offset = win->y_max / 11;
  int x_offset = (win->x_max / 7) + 13;

  WINDOW* win_form = derwin(win->window, 0, 0, 0, 0);
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
    *(fields + f) = new_field(1, 50,          // height and width
                              (f * y_offset), // start y
                              x_offset,       // start x
                              0, 10);         // render entire field and amount of buffers

    field_opts_off(*(fields + f), O_AUTOSKIP);
    // set field type with field validation
    set_field_back(*(fields + f), A_UNDERLINE);

    set_field_buffer(*(fields + f), f, *(data + f));
  }
    
  // create a new form and post it
  create_form = new_form(fields);

  scale_form(create_form, &rows, &cols);

  // set form window and sub-window
  set_form_win(create_form, win_form);
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
  handle_input(win, create_form, &key);

  for (int d = 0; d < 10; d++) {
    // if we are on the first two fields (first and last name)
    if (d < 2) {
      if (d == 1) {
        // get first and last name for concatenation
        char* first = field_buffer(*fields, 0); 
        char* last = field_buffer(*(fields + 1), 0);

        // trim whitespaces
        trim_whitespaces(first);
        trim_whitespaces(last);

        // copy first and last name into data array
        strcpy(*data, first);
        strcpy(*(data + 1), last);
      }


      char* cur_field = field_buffer(*(fields + d), 0);
      char* cur_str = *(data + d);
      trim_whitespaces(cur_field);
      strcpy(cur_str, cur_field);
    }
  }

  window_clear(win);
  // un-post form and free the memory
  unpost_form(create_form);
  free_form(create_form);
  for (int f = 0; f < 10; f++) {
    free_field(*(fields + f));
  }

  // hide cursor
  curs_set(0);

  return data;
}

