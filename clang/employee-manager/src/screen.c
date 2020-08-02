#include <ncurses.h>
#include <string.h>

#include "headers/employee.h"
#include "headers/window.h"
#include "headers/utils.h"

void print_employee(Window* win, char*** data, const int rows) {
  clear_screen(win);
  refresh();
  wrefresh(win->window);

  const char* Employee_Labels[] = {
    "Name", // 1 && 2
    "Email", // 3
    "Address", // 4
    "Phone", // 6
    "Title", // 9
  };

  const unsigned long int word_offset = (win->x_max / 5);
  unsigned int offset = 0;

  for (int y = 0; y < rows; y++) {    
    char* first = *(*(data + y) + 1);
    char* last = *(*(data + y) + 2);
    char* full_name = (char*) malloc((strlen(first) + strlen(last)) + 1);
    if (!full_name || full_name == NULL) {
      printf("ERROR: Failure to allocate memory for full name in print_employee\n");
      exit(1);
    }

    strcpy(full_name, first);
    strcat(full_name, " ");
    strcat(full_name, last);

    char* temp_data[5] = {
      full_name,
      *(*(data + y) + 3),
      *(*(data + y) + 4),
      *(*(data + y) + 6),
      *(*(data + y) + 5),
    };

    for (int l = 0; l < 5; l++) {
      const char* current_label = *(Employee_Labels + l);
      const unsigned long int current_label_length = strlen(current_label);

      mvwprintw(
        win->window,
        ((win->y_max + 1) - win->y_max),
        ((win->x_max + 1) - win->x_max) + word_offset + offset,
        current_label
      );

      offset += (current_label_length + 1) + word_offset;
    }

    char* screen_line = (char*) malloc((sizeof(char) * win->x_max) - 4);
    if (!screen_line || screen_line == NULL) exit(1); 
    for (int s = 0; s < win->x_max - 1; s++) {
      *(screen_line + s) = '-';
    }

    mvwprintw(
        win->window,
        ((win->y_max + 1) - win->y_max + 2),
        1,
        screen_line
    );

    refresh();
    wrefresh(win->window);

    offset = 0;

    for (int x = 0; x < 5; x++) {
      const char* current_value = *(temp_data + x);
      const unsigned long int current_value_length = strlen(current_value);

      mvwprintw(
        win->window,
        ((win->y_max + 1) - win->y_max + 4) + (y + 1),
        (((win->x_max + 1) - win->x_max) + word_offset + offset) - (current_value_length / 2),
        current_value
      );

      refresh();
      wrefresh(win->window);

      offset += ((current_value_length + 1) + word_offset) - (current_value_length / 2);
    } 
  
    offset = 0;
  }

  char return_label[] = "Press \"Escape\" to return to the main menu";
  mvwprintw(
    win->window,
    win->y_max - 5,
    (win->x_max / 2) - (strlen(return_label) / 2),
    return_label
  );

  refresh();
  wrefresh(win->window);
};

void print_search_label(Window* win, const char* label) {
  // get length of search form label
  int label_len = strlen(label);

  // clear screen
  clear_screen(win);

  // print search form label
  mvwprintw(win->window, win->y_max / 2, ((win->x_max / 2) - ((label_len / 2) - 1)), label);

  refresh();
  wrefresh(win->window);
};
