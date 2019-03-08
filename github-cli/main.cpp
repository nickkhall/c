#include <iostream>
#include <unistd.h>
#include <ncurses.h>

using namespace std;

void printIntro(WINDOW* window, int xMax) {
  sleep(1);
  mvwprintw(window, 1, (xMax / 2) - (25 / 2), "Welcome to the Github CLI");
  wrefresh(window);
  sleep(1);
  mvwprintw(window, 3, (xMax / 2) - (54 / 2),  "  _____ _ _   _           _        _____ _      _____ ");
  mvwprintw(window, 4, (xMax / 2) - (54 / 2),  " \/ ____(_) | | |         | |      \/ ____| |    |_   _|");
  mvwprintw(window, 5, (xMax / 2) - (54 / 2),  "| |  __ _| |_| |__  _   _| |__   | |    | |      | |  ");
  mvwprintw(window, 6, (xMax / 2) - (54 / 2),  "| | |_ | | __| '_ \\| | | | '_ \\  | |    | |      | |  ");
  mvwprintw(window, 7, (xMax / 2) - (54 / 2),  "| |__| | | |_| | | | |_| | |_) | | |____| |____ _| |_ ");
  mvwprintw(window, 8, (xMax / 2) - (54 / 2), " \\_____|_|\\__|_| |_|\\__,_|_.__\/   \\_____|______|_____|");
  wrefresh(window);
  sleep(3);
}

int main(int argc, char ** argv) {
  // Initialize NCurses screen
  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // Create window
  WINDOW* window = newwin(0, 0, 0, 0);
  refresh();

  box(window, 0, 0);
  wrefresh(window);

  printIntro(window, xMax);

  // Enable arrow keys
  keypad(window, true);

  // string choices[3] = {"Create Repository", "Update Repository", "Clone Repository"};
  // int choice;
  // int highLight = 0;
  //
  // while(1) {
  //   for(int c = 0; c < 3; c++) {
  //     // For selected option, turn on attribute reverse,
  //     // which reverses the color scheme. (white bg, black text)
  //     if(c == highLight) {
  //       wattron(window, A_REVERSE);
  //     }
  //
  //     // Regardless, move to x,y coord and print option
  //     mvwprintw(window, c + 2, 10, choices[c].c_str());
  //     // Turn off attribute.
  //     wattroff(window, A_REVERSE);
  //   }
  //
  //   choice = wgetch(window);
  //
  //
  //   switch(choice) {
  //     case KEY_UP:
  //       highLight--;
  //       if (highLight == -1) {
  //         highLight = 0;
  //       }
  //       break;
  //     case KEY_DOWN:
  //       highLight++;
  //       if (highLight == 3) {
  //         highLight = 2;
  //       }
  //       break;
  //     default:
  //       break;
  //   }
  //
  //   // If user hits 'Enter' key
  //   if(choice == 10) {
  //     // Do things if user hits 'Enter'
  //
  //     // Break out of while loop
  //     break;
  //   }
  // }

  getch();

  // Close window
  endwin();

  return 0;
}
