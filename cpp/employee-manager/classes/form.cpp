#include <ncurses.h>
#include <iostream>
#include <cstring>

#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form() {};

void Form::CollectInfo() {
  int key_code {0};

  ClearScreen();

  curs_set(1);

  do {
    mvwprintw(window, y_max / 2, (x_max / 2) - 4, "test");
    
    refresh();
    wrefresh(window);
  } while (key_code != 27 || key_code != 10);
};

// void Form::Create(const unsigned int &type) {
//   curs_set(1);
// 
//   switch(type) {
//     // Employee type
//     case 0: {
//        Employee NewEmployee;
//        NewEmployee = NewEmployee.CreateEmployee();
//     }
//   };
// 
// };

Form::~Form() {};
