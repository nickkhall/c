#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu {
  private:
    unsigned short int highlighted;
    unsigned short int menu_selected;

  public:
    std::vector<std::string> menu_items;

    Menu(const std::vector<std::string> &menu_items);
    void PrintMenu(); 

};

#endif
