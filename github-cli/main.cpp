#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <cstring>

using namespace std;

void clearScreen() {
  clear();
}

void printMenu(WINDOW *window, string items[], int size, int highLighted) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int menuY = yMax / 2;
  int menuX = xMax / 2;

  for(int c = 0; c < size; c++) {
    // For selected option, turn on attribute reverse,
    // which reverses the color scheme. (white bg, black text)
    if(c == highLighted) {
      wattron(window, A_REVERSE);
    }

    // Regardless, move to x,y coord and print option
    mvwprintw(window, menuY + (c + 2), menuX - (strlen(items[c].c_str()) / 2), items[c].c_str());
    // Turn off attribute.
    wattroff(window, A_REVERSE);
  }
}

void changeMenuChoice(int *choice, int *highLighted) {
  switch(*choice) {
    case KEY_UP:
      *highLighted--;
      if (*highLighted == -1) {
        *highLighted = 0;
      }
      break;
    case KEY_DOWN:
      *highLighted++;
      if (*highLighted == 3) {
        *highLighted = 2;
      }
      break;
    default:
      break;
  }
}

void printFrame(WINDOW* window) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  box(window, 0, 0);
  sleep(1);
  mvwprintw(window, 1, (xMax / 2) - (25 / 2), "Welcome to the Github CLI");
  wrefresh(window);
  mvwprintw(window, 3, (xMax / 2) - (54 / 2),  "  _____ _ _   _           _        _____ _      _____ ");
  mvwprintw(window, 4, (xMax / 2) - (54 / 2),  " / ____(_) | | |         | |      / ____| |    |_   _|");
  mvwprintw(window, 5, (xMax / 2) - (54 / 2),  "| |  __ _| |_| |__  _   _| |__   | |    | |      | |  ");
  mvwprintw(window, 6, (xMax / 2) - (54 / 2),  "| | |_ | | __| '_ \\| | | | '_ \\  | |    | |      | |  ");
  mvwprintw(window, 7, (xMax / 2) - (54 / 2),  "| |__| | | |_| | | | |_| | |_) | | |____| |____ _| |_ ");
  mvwprintw(window, 8, (xMax / 2) - (54 / 2), " \\_____|_|\\__|_| |_|\\__,_|_.__/   \\_____|______|_____|");
  refresh();
  wrefresh(window);
  sleep(1);
}

int mainMenu(WINDOW* window, int* choice) {
  int highLighted = 0;
  string choices[3] = {
    "Create Repository",
    "Update Repository",
    "Clone  Repository"
  };

  do {
    printMenu(window, choices, 3, highLighted);
    *choice = wgetch(window);

  } while (*choice != 27 && *choice != 10);

  if (*choice == 27) {
    return -1;
  }

  if (*choice == 0) {
    return 1;
  }

  refresh();
  wrefresh(window);
}

int main(int argc, char ** argv) {
  // Initialize NCurses screen
  initscr();
  noecho();
  curs_set(0);


  // Create window
  WINDOW* window = newwin(0, 0, 0, 0);
  refresh();

  // Enable arrow keys
  keypad(window, true);

  int menu = 0;
  int highLighted = 0;
  int choice = 0;


  do {
    printFrame(window);

    switch(menu) {
      case 0:
        menu = mainMenu(window, &choice);
        break;
      default:
        break;
    }
  } while(menu != -1);

  erase();
  // Close window
  endwin();

  return 0;
}
