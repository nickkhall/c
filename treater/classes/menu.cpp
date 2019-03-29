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

/**
 * Overloaded Menu constructor.
 * @param {!Vector<string>} items The items to be rendered in the menu.
 */
Menu::Menu(std::vector<std::string> items)
 : items {items},
   selected {0},
   highlighted {0}
{
  PaginateItems();
}

/**
 * Returns the currently selected item.
 * @return {int} The number (item) selected.
 */
int Menu::GetMenuSelected() {
  return selected;
}

/**
 * Prints a menu to the screen.
 * @param {Window*} window A pointer to a Window class instance.
 * @param {int} yDividend The number to divide the height by for the y menu position.
 * @param {int} xDividend The number to divide the height by for the x menu position.
 * @return {int} The number (item) selected from the menu.
 */
int Menu::PrintMenu(Window* window, int yDividend, int xDividend) {
  int keyCode = 0;
  int y = (yDividend != 0) ? yDividend : 2;
  int x = (xDividend != 0) ? xDividend : 2;

  do {
    // If the currently selected item is Next Page
    if (itemsContainer[pageNum][highlighted] == "-----Next Page-----") {
      // Increment the page number.
      pageNum++;
      // Reset the highlighted to the top of the list.
      highlighted = 1;
      // Clear the screen so the new set of items can be rendered.
      window->ClearScreen();
    }

    // If the currently selected item is Previous Page
    if (itemsContainer[pageNum][highlighted] == "-----Previous Page-----") {
      // Decrement the page number.
      pageNum--;
      // Set the currently highlighted item as the last item in the items.
      highlighted = itemsContainer[pageNum].size() - 2;
      // Clear the screen so the new set of items can be rendered.
      window->ClearScreen();
    }

    refresh();
    wrefresh(window->windowInstance);

    // Iterate over current list to render
    for (int i = 0; i < itemsContainer[pageNum].size(); i++) {
      // If the current item in list matches the number of highlighted
      if (i == highlighted) {
        // Switch the colors (white bg, black text)
        wattron(window->windowInstance, A_REVERSE);
      }

      // Move to y, x coordinates and print current item
      mvwprintw(
        window->windowInstance,
        window->yMax / y + (i + 2),
        window->xMax / x - (strlen(itemsContainer[pageNum][i].c_str()) / 2),
        itemsContainer[pageNum][i].c_str()
      );

      // Turn off reverse attribute
      wattroff(window->windowInstance, A_REVERSE);
    }

    refresh();
    wrefresh(window->windowInstance);

    // Get the users new choice
    keyCode = wgetch(window->windowInstance);

    // Set the currently selected item to what the user chose.
    SetMenuSelected(keyCode);
  } while (keyCode != 27 && keyCode != 10); // As long as the user does not hit "Escape" or "Enter".

  // Return the selected item (+1 cause 0 based)
  return (selected + 1);
}

/**
 * Sets the currently selected item.
 * @param {int} keyCode The key code to determine whether or not to increment or decrement the currently highlighed item.
 */
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

/**
 * Turns items list longer than 30 into a list of lists (paginating).
 */
void Menu::PaginateItems() {
  // Set a temporary list to keep track of sub lists.
  std::vector<std::string> tempVec {};

  // Iterate over entire items list
  for (int i = 0; i < items.size(); i++) {
    // If not the first item, and for every 30'th item
    if (i != 0 && i % 30 == 0) {
      // Push the current item onto temp list
      tempVec.push_back(items[i]);
      // Push a new line character onto temp list
      tempVec.push_back("\n");
      // Push a Next Page item for handling going to the next page
      tempVec.push_back("-----Next Page-----");
      // Push temp list onto master list of lists
      itemsContainer.push_back(tempVec);
      // Clear the temp list
      tempVec.clear();
    } else {
      // Otherwise, push item onto temp list
      tempVec.push_back(items[i]);
    }
  }

  // Finally, push remaining items list onto master list of lists (this list will be under 30)
  itemsContainer.push_back(tempVec);

  // Iterate over master list of lists
  for (int x = 0; x < itemsContainer.size(); x++) {
    if (x > 0) {
      // For all lists other than the first, add Previous Page item to the begining of that list
      itemsContainer[x].insert(itemsContainer[x].begin(), "-----Previous Page-----");
    }
  }
}
