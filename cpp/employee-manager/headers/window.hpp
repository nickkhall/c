#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

class Window {
  public:
    unsigned int y_max;
    unsigned int x_max;
    WINDOW *window;

    Window();

    void PrintHeader();
};

#endif
