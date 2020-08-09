#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "headers/screen.h"

#include "headers/employee.h"
#include "headers/window.h"
#include "headers/menu.h"
#include "headers/utils.h"

const char SEARCH_LABEL[] = "Search by ID, First and/or Last name:";
const char* CREATE_LABELS[] = {
  "First*    : ",
  "Last*     : ",
  "Email*    : ",
  "Address   : ",
  "Phone     : ",
  "Start     : ",
  "Gender    : ",
  "Ethnicity : ",
  "Title*    : ",
  "Salary*   : "
};

void screen_print_word(Window* win, const int y, const int x, const char* word) {
  mvwprintw(win->window, y, x, word);
  
  window_refresh(win);
}

void screen_print_border(Window* win) {
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

  window_refresh(win);
};

void screen_print_line(Window* win, const int y) {
  // render a horizonal line for data separation
  char* screen_print_line = (char*) malloc((sizeof(char) * win->x_max) - 4);
  if (!screen_print_line || screen_print_line == NULL) exit(1); 
  for (int s = 0; s < win->x_max - 1; s++) {
    *(screen_print_line + s) = '-';
  }

  // print horizontal line
  screen_print_word(win,
                    ((win->y_max + 1) - win->y_max + 2),
                    y,
                    screen_print_line
  );

  // free screen line memory
  free(screen_print_line);
};

void screen_print_employee_headers(Window* win) {
  const unsigned long int word_offset = (win->x_max / 7);

  // keep track of current x axis offset for n value
  unsigned int offset = word_offset;

  // print the employee table header labels
  for (int l = 0; l < 5; l++) {
    const char* current_label = *(employee_labels_mini + l);
    const unsigned long int current_label_length = strlen(current_label);

    screen_print_word(win, 1, offset, current_label);

    // increase the x axis offset for next label
    offset += word_offset + current_label_length;
  }
};

void screen_print_employee_row_none(Window* win, const int row) {
  char no_employees_text[] = "No employees found.";

  screen_print_word(win,
                    row + 4,
                    (win->x_max / 2) - (strlen(no_employees_text) / 2),
                    no_employees_text); 
}

void screen_print_employee_row(Window* win, Employee* employee, const int row) {
  // allocate memory for first and last name string
  unsigned long int first_size = strlen(employee->first);
  unsigned long int last_size = strlen(employee->last);

  char* name = malloc(first_size + last_size);
  if (!name || name == NULL) {
    printf("ERROR::Failed to allocate memory for name in screen_print_employee_row\n");
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
    screen_print_word(win, (row + 4), offset, cur_value); 

    offset += word_offset + (strlen(cur_value) / 2);
  }

  free(name);
};

void screen_print_employee(Window* win, Employee* employee) {
  int cur_row = 0;
  window_clear(win);

  screen_print_employee_headers(win);

  screen_print_line(win, 1);

  // if there were no employees found
  if (employee == NULL) {
    // print out no users found to table
    screen_print_employee_row_none(win, cur_row++);
    return;
  }

  // if we make it here, have employee data,
  // so print it to the screen
  while(employee != NULL) {
    // print employee row with employee data
    screen_print_employee_row(win, employee, cur_row++);
    // advance the list
    employee = employee->next_employee;
  }

  // print helper label text for returning to menu at bottom of screen
  char return_label[] = "Press \"Escape\" to return to the main menu";
  // print helper label at bottom of the screen
  screen_print_word(win,
            win->y_max - 5,
            (win->x_max / 2) - (strlen(return_label) / 2),
            return_label);
};

void screen_print_search_label(Window* win) {
  // get length of search form label
  int label_len = strlen(SEARCH_LABEL);

  // clear screen
  window_clear(win);

  // print search form label
  screen_print_word(
    win,
    win->y_max / 2,
    ((win->x_max / 2) - ((label_len / 2) - 1)),
    SEARCH_LABEL
  );

  refresh();
  wrefresh(win->window);
};

void screen_print_title(Window *win) {
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
    screen_print_word(
      win,
      i + 10,
      ((win->x_max / 2) - (91 / 2) + 2),
      *(header + i)
    );
  }

  window_refresh(win);
};

void screen_print_menu(Window *win, Menu* menu, int menu_items_size) {
  int key_code = 0;

  do {
    window_refresh(win);

    for (int i = 0; i < menu_items_size; i++) {
      if (i == menu->highlighted) {
        // reverse colors to denote highlight
        wattron(win->window, A_REVERSE);
      }

      screen_print_word(
        win,
        win->y_max / 2 + (i + 2),
        (win->x_max / 2) - menu_items_size,
        *(menu->items + i)
      );

      // Turn off reverse attribute
      wattroff(win->window, A_REVERSE);
    }

    // refresh window
    window_refresh(win);

    key_code = wgetch(win->window);

    // Update the menu with the currently selected item
    menu_update(menu, key_code, menu_items_size);
  } while (key_code != 27 && key_code != 10);
}

void screen_print_form_labels(Window* win, char** labels) {
  
}

void screen_print_form_labels_create(Window* win) {
  window_clear(win);
  int offset = (win->y_max / 11);

  for (int l = 0; l < 11; l++) {
    char* cur_label = *(CREATE_LABELS + l);

    screen_print_word(win, offset, win->x_max / 7, cur_label);
    if (l % 1 == 0) {
      offset++;
      screen_print_word(win, offset, win->x_max / 7, "-----------");
    }

    offset += (win->y_max / 11) - 1;
  }

  window_refresh(win);
}

