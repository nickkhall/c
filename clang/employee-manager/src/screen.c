#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "headers/employee.h"
#include "headers/window.h"
#include "headers/utils.h"

void print_word(Window* win, const int y, const int x, const char* word) {
  mvwprintw(win->window, y, x, word);
  
  refresh();
  wrefresh(win->window);
}

void print_border(Window* win) {
  for (int y = 0; y < win->y_max; y++) {
    for (int x = 0; x < win->x_max; x++) {
      if (y > 0) {
        // print corners
        if ((y == 1 && x == 2)
          || (y == 1 && x == win->x_max - 3)
          || (y == win->y_max - 2 && x == 2)
          || (y == win->y_max - 2 && x == win->x_max - 3)
        ) { 
          mvwprintw(win->window, y, x, "+");
          // print vertical borders
        } else if (y > 1 && y < win->y_max - 2 && (x == 2 || x == win->x_max - 3)) {
          mvwprintw(win->window, y, x, "|");
          // print horizontal borders
        } else if (x > 2 && x < (win->x_max - 3) && (y == 1 || y == win->y_max - 2)) {
          mvwprintw(win->window, y, x, "-");
        }
      }
    }
  }

  refresh();
  wrefresh(win->window);
};

void print_screen_line(Window* win, const int y) {
  // render a horizonal line for data separation
  char* screen_line = (char*) malloc((sizeof(char) * win->x_max) - 4);
  if (!screen_line || screen_line == NULL) exit(1); 
  for (int s = 0; s < win->x_max - 1; s++) {
    *(screen_line + s) = '-';
  }

  // print horizontal line
  print_word(
    win,
    ((win->y_max + 1) - win->y_max + 2),
    y,
    screen_line
  );

  // free screen line memory
  free(screen_line);
};

void print_employee_headers(Window* win) {
  const unsigned long int word_offset = (win->x_max / 7);

  // keep track of current x axis offset for n value
  unsigned int offset = word_offset;

  // print the employee table header labels
  for (int l = 0; l < 5; l++) {
    const char* current_label = *(employee_labels_mini + l);
    const unsigned long int current_label_length = strlen(current_label);

    print_word(win, 1, offset, current_label);

    // increase the x axis offset for next label
    offset += word_offset + current_label_length;
  }
};

void print_employee_row(Window* win, Employee* employee, const int row) {
  // allocate memory for first and last name string
  char* name = malloc(strlen(employee->first) + strlen(employee->last) + 2);
  if (!name || name == NULL) {
    printf("ERROR::Failed to allocate memory for name in print_employee_row\n");
    free(name);
    exit(1);
  }

  // generate string for first and last name
  strcpy(name, employee->first);
  strcat(name, " ");
  strcat(name, employee->last);

  char* temp_data[5] = {name,
                        employee->email,
                        employee->address,
                        employee->phone,
                        employee->title};

  // keep track of offset that labels should render apart from eachother (x axis)
  unsigned long int word_offset = (win->x_max / 7);

  // keep track of current x axis offset for n value
  unsigned int offset = (word_offset - strlen(*(temp_data)) / 2);

  for (int e = 0; e < 5; e++) {
    char * cur_value = *(temp_data + e);
    print_word(win, (row + 4), offset, cur_value); 

    offset += word_offset + (strlen(cur_value) / 2);
  }

  free(name);
};

void print_employee(Window* win, Employee* employee) {
  int cur_row = 0;
  clear_screen(win);

  print_employee_headers(win);

  print_screen_line(win, 1);

  while(employee->next_employee != NULL) {
    print_employee_row(win, employee, cur_row++);
    employee = employee->next_employee;
  }

  // print helper label text for returning to menu at bottom of screen
  char return_label[] = "Press \"Escape\" to return to the main menu";
  print_word(win,
            win->y_max - 5,
            (win->x_max / 2) - (strlen(return_label) / 2),
            return_label);
};

void print_search_label(Window* win, const char* label) {
  // get length of search form label
  int label_len = strlen(label);

  // clear screen
  clear_screen(win);

  // print search form label
  print_word(
    win,
    win->y_max / 2,
    ((win->x_max / 2) - ((label_len / 2) - 1)),
    label
  );

  refresh();
  wrefresh(win->window);
};

void print_title(Window *window) {
  const char* header[] = {
    " ______                 _                         __  __",
    "|  ____|               | |                       |  \\/  |",
    "| |__   _ __ ___  _ __ | | ___  _   _  ___  ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __",
    "|  __| | '_ ` _ \\| '_ \\| |/ _ \\| | | |/ _ \\/ _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|",
    "| |____| | | | | | |_) | | (_) | |_| |  __/  __/ | |  | | (_| | | | | (_| | (_| |  __/ |",
    "|______|_| |_| |_| .__/|_|\\___/ \\__, |\\___|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|",
    "                 | |             __/ |                                      __/ |",
    "                 |_|            |___/                                      |___/"
  };

  for (short int i = 0; i < 8; i++) {
    mvwprintw(
      window->window,
      i + 10,
      ((window->x_max / 2) - (91 / 2) + 2),
      *(header + i)
    );
  }

  refresh();
  wrefresh(window->window);
};
