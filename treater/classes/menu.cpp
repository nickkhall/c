#include <ncurses.h>
#include <vector>
#include <string>

#include "../headers/menu.hpp"
#include "../headers/window.hpp"

// Default Constructor
Menu::Menu(std::string type, std::vector<std::string> items) :
  type {type}, items {items}, selected {0}
{}

// Generate Menu
void Menu::GenerateMenu(Window* window, int selected) {
  SetMenuYPosXPos(window->yMax, window->xMax);

  std::cout << "GenerateMenu after SetMenuYPosXPos" << std::endl;

  for (int i = 0; i < 3; i++) {
    if (i == selected) {
      wattron(window->windowInstance, A_REVERSE);
    }

    // Move to y, x coordinates and print current item
    mvwprintw(window->windowInstance, yPos + (i + 2), xPos - (strlen(items[i].c_str()) / 2), items[i].c_str());

    // Turn off reverse attribute
    wattroff(window->windowInstance, A_REVERSE);
  }
  
  wrefresh(window->windowInstance);
}

// Get's Menu Type
std::string Menu::GetMenuType() {
  return type;
}

// Get's Menu's Current Choice
int Menu::GetMenuSelected() {
  std::cout << "Selected: " << selected << std::endl;
  return selected;
}

// Set's Menu's Current Choice
void Menu::SetMenuSelected (int keyCode) {
  switch(keyCode) {
    // Up Arrow Key
    case 38:
      selected = selected - 1;
      if (selected == -1) {
        selected = 0;
      }
      break;
    // Down Arrow Key
    case 40:
      selected = selected + 1;
      if (selected == 3) {
        selected = 2;
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

void Menu::SetMenuYPosXPos(int y, int x) {
  yPos = y / 2;
  xPos = x / 2;
}
