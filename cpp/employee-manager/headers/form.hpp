#ifndef FORM_H
#define FORM_H

#include <vector>
#include <string>

#include "./window.hpp"

class Form : public Window {
  public:
    Form();

    void Create(const std::vector<std::string> &form_items);

    ~Form();
  private:
    std::vector<std::string> form_items;
};

#endif
