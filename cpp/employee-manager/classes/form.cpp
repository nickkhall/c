#include <ncurses.h>
#include <vector>

#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form() {};

void Form::Create() {
  int key_code {0};

  ClearScreen();

  curs_set(1);

  for (int i = 0; i < form_items.size(); i++) {
    mvwprintw(window, y_max / 2, (x_max / 2) - 4, form_items[i].c_str());
  }
    
};

Form::~Form() {};
