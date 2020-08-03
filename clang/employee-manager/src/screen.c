#include <ncurses.h>
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
        if (
          (y == 1 && x == 2)
          || (y == 1 && x == win->x_max - 3)
          || (y == win->y_max - 2 && x == 2)
          || (y == win->y_max - 2 && x == win->x_max - 3)
        ) { 
          mvwprintw(win->window, y, x, "+");
          
          refresh();
          wrefresh(win->window);
          // print vertical borders
        } else if (y > 1 && y < win->y_max - 2 && (x == 2 || x == win->x_max - 3)) {
          mvwprintw(
            win->window,
            y,
            x,
            "|"
          );

          refresh();
          wrefresh(win->window);
          // print horizontal borders
        } else if (x > 2 && x < (win->x_max - 3) && (y == 1 || y == win->y_max - 2)) {
          mvwprintw(
            win->window,
            y,
            x,
            "-"
          );

          refresh();
          wrefresh(win->window);
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
  unsigned int offset = 0;

  // print the employee table header labels
  for (int l = 0; l < 5; l++) {
    const char* current_label = *(employee_labels + l);
    const unsigned long int current_label_length = strlen(current_label);

    print_word(
      win,
      1,
      ((((win->x_max + 1) - win->x_max) + word_offset + offset) - (current_label_length / 2)) + (l + 1),
      current_label
    );

    // increase the x axis offset for next label
    offset += ((current_label_length / 2) + word_offset) + (l + 1);
  }
};

void print_employee_row(Window* win, char** data, const int row) {
  // keep track of offset that labels should render apart from eachother (x axis)
  const unsigned long int word_offset = (win->x_max / 7);

  // keep track of current x axis offset for n value
  unsigned int offset = 0;

  // render minified employee data
  for (int x = 0; x < 5; x++) {
    const char* current_value = *(data + x);
    const unsigned long int current_value_length = strlen(current_value);
    const char* current_label = *(employee_labels + x);
    const unsigned long int current_label_length = strlen(current_label);

    print_word(
      win,
      ((win->y_max + 1) - win->y_max + 4) + row,
      (((win->x_max + 1) - win->x_max) + word_offset + offset) - ((current_value_length / 2) - x),
      current_value
    );

    // increase offset of current data length
    //offset += ((current_label_length / 2) - (x + 1)) + (current_value_length / 2) + word_offset;
    offset += ((current_label_length) + word_offset);
  } 
};

void print_employee(Window* win, char*** data, const int rows) {
  clear_screen(win);

  // print out employee(s) data in table format
  for (int y = 0; y < rows; y++) {
    // get first name
    char* first = *(*(data + y) + 1);
    // get last name
    char* last = *(*(data + y) + 2);
    // combined first and last name
    char* full_name = (char*) malloc((strlen(first) + strlen(last)) + 1);
    if (!full_name || full_name == NULL) {
      printf("ERROR: Failure to allocate memory for full name in print_employee\n");
      exit(1);
    }

    // copy first and last to combined string
    strcpy(full_name, first);
    strcat(full_name, " ");
    strcat(full_name, last);

    // cherry pick data
    // @TODO: Remove when screen size logic is added to allow for more data to be displayed
    char* temp_data[5] = {
      full_name,
      *(*(data + y) + 3),
      *(*(data + y) + 4),
      *(*(data + y) + 5),
      *(*(data + y) + 9),
    };

    print_employee_headers(win);

    print_screen_line(win, 1);

    print_employee_row(win, temp_data, y);
  }

  // print helper label text for returning to menu at bottom of screen
  char return_label[] = "Press \"Escape\" to return to the main menu";
  print_word(
    win,
    win->y_max - 5,
    (win->x_max / 2) - (strlen(return_label) / 2),
    return_label
  );
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
