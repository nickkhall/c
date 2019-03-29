#include <ncurses.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/menu.hpp"
#include "../headers/window.hpp"

// Overloaded Constructor with list
Menu::Menu(std::vector<std::string> items)
 : items {items},
   selected {0},
   highlighted {0}
{
  PaginateItems();
}

// Get's Menu's Current Choice
int Menu::GetMenuSelected() {
  return selected;
}

int Menu::PrintMenu(Window* window, int yDividend, int xDividend) {
  int keyCode = 0;
  int y = (yDividend != 0) ? yDividend : 2;
  int x = (xDividend != 0) ? xDividend : 2;

  do {
    if (itemsContainer[pageNum][highlighted] == "-----Next Page-----") {
      pageNum++;
      highlighted = 1;
      window->ClearScreen();
    }

    if (itemsContainer[pageNum][highlighted] == "-----Previous Page-----") {
      pageNum--;
      highlighted = itemsContainer[pageNum].size() - 2;
      window->ClearScreen();
    }

    refresh();
    wrefresh(window->windowInstance);

    for (int i = 0; i < itemsContainer[pageNum].size(); i++) {
      if (i == highlighted) {
        wattron(window->windowInstance, A_REVERSE);
      }

      int curY = window->yMax / y + (i + 2);

      // Move to y, x coordinates and print current item
      mvwprintw(
        window->windowInstance,
        curY,
        window->xMax / x - (strlen(itemsContainer[pageNum][i].c_str()) / 2),
        itemsContainer[pageNum][i].c_str()
      );

      // Turn off reverse attribute
      wattroff(window->windowInstance, A_REVERSE);
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
    // Down
    case KEY_DOWN:
      // Prevent user from selecting item above list
      if (highlighted + 1 < itemsContainer[pageNum].size()) {
        highlighted = highlighted + 1;
      }
      break;
    // Up
    case KEY_UP:
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

void Menu::PaginateItems() {
  std::vector<std::string> tempVec {};

  for (int i = 0; i < items.size(); i++) {
    if (i != 0 && i % 30 == 0) {
      tempVec.push_back(items[i]);
      tempVec.push_back("\n");
      tempVec.push_back("-----Next Page-----");
      itemsContainer.push_back(tempVec);
      tempVec.clear();
    } else {
      tempVec.push_back(items[i]);
    }
  }

  itemsContainer.push_back(tempVec);

  for (int x = 0; x < itemsContainer.size(); x++) {
    if (x > 0) {
      itemsContainer[x].insert(itemsContainer[x].begin(), "-----Previous Page-----");
    }
  }
}
