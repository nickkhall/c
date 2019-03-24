#include <ncurses.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>

#include "../headers/menu.hpp"
#include "../headers/window.hpp"

// Overloaded Constructor with list
Menu::Menu(std::vector<std::string> items)
 : items {items}, selected {0}, highlighted {0}
{}

// Get's Menu's Current Choice
int Menu::GetMenuSelected() {
  return selected;
}

int Menu::PrintMenu(Window* window, int yDividend, int xDividend) {
  int keyCode = 0;
  int y = (yDividend != 0) ? yDividend : 2;
  int x = (xDividend != 0) ? xDividend : 2;

  do {
    for (int i = 0; i < items.size(); i++) {
      if (i == highlighted) {
        wattron(window->windowInstance, A_REVERSE);
      }

      int curY = window->yMax / y + (i + 2);
      
      // Move to y, x coordinates and print current item
      mvwprintw(
        window->windowInstance,
        curY,
        window->xMax / x - (strlen(items[i].c_str()) / 2),
        items[i].c_str()
      );

      // Turn off reverse attribute
      wattroff(window->windowInstance, A_REVERSE);

      // 47 will fit on screen
    }

    refresh();
    wrefresh(window->windowInstance);

    keyCode = wgetch(window->windowInstance);

    SetMenuSelected(keyCode);
  } while (keyCode != 27 && keyCode != 10);

  return (selected + 1);
}

// Set's Menu's Current Choice
void Menu::SetMenuSelected (int keyCode) {
  switch(keyCode) {
    // Up Arrow Key
    case 258:
      // Prevent user from selecting item above list
      if (highlighted + 1 < items.size()) {
        highlighted = highlighted + 1;
      }
      break;
    // Down Arrow Key
    case 259:
      // Prevent user from selecting item below list
      if (highlighted - 1 > -1) {
        highlighted = highlighted - 1;
      }
      break;
    default:
      break;
  }

  selected = highlighted;
}

void Menu::PopulateItemsFromFile(std::string filepath) {
  std::string line;
  std::ifstream data(filepath);

  while (!data.eof()) {
    getline(data, line);
    items.push_back(line);
  }

  data.close();
}
