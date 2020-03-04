#include <vector>
#include <string>
#include <iostream>

#include <cstring>
#include <ncurses.h>

#include "../headers/menu.hpp"
#include "../headers/window.hpp"

Menu::Menu(const std::vector<std::string> &menu_items)
  : menu_items {menu_items}, highlighted {0}
{};

int Menu::PrintMenu(Window *window) {
  std::cout << "\033[2J\033[1;1H";

  int key_code {0};
  int y = 2;
  int x = 2;

  do {
    refresh();
    wrefresh(window->window);

    for (int i = 0; i < menu_items.size(); i++) {
      if (i == highlighted) {
        wattron(window->window, A_REVERSE);
      }

      mvwprintw(
        window->window,
        window->y_max / 2 + (i + 2),
        window->x_max / 2 - (strlen(menu_items[i].c_str()) / 2),
        menu_items[i].c_str()
      );

      // Turn off reverse attribute
      wattroff(window->window, A_REVERSE);
    }

    refresh();
    wrefresh(window->window);

    key_code = wgetch(window->window);

    // Update the menu with the currently selected item
    SetMenuSelected(key_code);
  } while (key_code != 27 && key_code != 10); // As long as the user does not hit the "Escape" or "Enter" key

  return (menu_selected + 1);
};

void Menu::SetMenuSelected(int key_code) {
  switch(key_code) {
    case KEY_DOWN:
      // Prevent the user from selecting item above the list
      if (highlighted + 1 < menu_items.size()) {
        highlighted += 1;
      }
      break;
    case KEY_UP:
        // Prevent user from selecting item below the list
        if (highlighted - 1 > -1) {
          highlighted -= 1;
        }
        break;
    default:
      break;
  };

  menu_selected = highlighted;
};

