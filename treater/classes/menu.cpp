#include <ncurses.h>
#include <vector>
#include <string>
#include <cstring>

#include "../headers/menu.hpp"
#include "../headers/window.hpp"

// Default Constructor
Menu::Menu(std::string type, std::vector<std::string> items) :
  type {type}, items {items}, selected {0}
{}

// Get's Menu Type
std::string Menu::GetMenuType() {
  return type;
}

// Get's Menu's Current Choice
int Menu::GetMenuSelected() {
  return selected;
}

int Menu::PrintMenu(Window* window) {
  window->PrintHeader();

  int keyCode = 0;

  do {
    for (int i = 0; i < 3; i++) {
      if (i == highlighted) {
        wattron(window->windowInstance, A_REVERSE);
      }

      // Move to y, x coordinates and print current item
      mvwprintw(window->windowInstance, yPos + (i + 2), xPos - (strlen(items[i].c_str()) / 2), items[i].c_str());

      // Turn off reverse attribute
      wattroff(window->windowInstance, A_REVERSE);
    }

    refresh();
    wrefresh(window->windowInstance);

    keyCode = wgetch(window->windowInstance);

    SetMenuSelected(keyCode);
  } while (keyCode != 27 && keyCode != 10);

  if (selected == 1) {
    return 1;
  }

  return 0;
}

// Set's Menu's Current Choice
void Menu::SetMenuSelected (int keyCode) {
  switch(keyCode) {
    // Up Arrow Key
    case 258:
      highlighted = highlighted + 1;
      if (highlighted == 3) {
        highlighted = 2;
      }
      break;
    // Down Arrow Key
    case 259:
      highlighted = highlighted - 1;
      if (highlighted == -1) {
        highlighted = 0;
      }
      break;
    default:
      break;
  }
}

int Menu::GetXPos() {
  return xPos;
}

int Menu::GetYPos() {
  return yPos;
}

void Menu::SetMenuYPosXPos(Window* window) {
  yPos = window->yMax / 2;
  xPos = window->xMax / 2;
}
