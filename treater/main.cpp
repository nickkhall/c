#include <iostream>
#include <ncurses.h>
#include <vector>

#include "headers/menu.hpp"
#include "headers/window.hpp"

using namespace std;

int main() {
  // Create window
  Window NewWindow;

  vector<string> mainMenuItems {"Add Review", "List Reviews", "Quit"};
  Menu MainMenu("main", mainMenuItems);

  MainMenu.GenerateMenu(&NewWindow, MainMenu.selected);

  do {
    MainMenu.GenerateMenu(&NewWindow, MainMenu.selected);
    int ch = getch();

    MainMenu.SetMenuSelected(ch);
  } while (MainMenu.GetMenuSelected() != 2);

  erase();
  // Close window
  endwin();

  return 0;
}
