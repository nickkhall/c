#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../headers/window.hpp"

class Menu {
  private:
    short int highlighted;
    short int menu_selected;

  public:
    std::vector<std::string> menu_items;

    Menu(const std::vector<std::string> &menu_items);
    
    int PrintMenu(Window *window); 
    int SetMenuSelected(int key_code);
};

#endif
