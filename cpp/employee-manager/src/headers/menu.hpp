#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../headers/window.hpp"

class Menu {
  private:
		std::vector<std::string> items{};
    short int highlighted;
    short int state;

  public:
    std::vector<std::string> menu_items;

    Menu(const std::vector<std::string> &menu_items);
    
    int render_menu(Window *window); 
    void update_state(int key_code);
};

#endif
