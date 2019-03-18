#include <iostream>
#include <ncurses.h>
#include <vector>

#include "classes/menu.cpp"
#include "classes/window.cpp"

using namespace std;

int main() {
  vector<string> mainMenuItems {"Add Review", "List Reviews", "Quit"};
  Menu MainMenu("main", mainMenuItems);

  // Create window
  Window* NewWindow;
  NewWindow->ConfigureWindow();

  do {
    MainMenu.GenerateMenu(NewWindow, MainMenu.selected);
    int ch = getch();

    MainMenu.SetMenuSelected(ch);
  } while (MainMenu.GetMenuSelected() != 2);

  erase();
  // Close window
  endwin();

  return 0;
}
