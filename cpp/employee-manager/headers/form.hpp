#ifndef FORM_H
#define FORM_H

#include <vector>
#include <string>

#include "./window.hpp"

class Form : public Window {
  public:
    Form();

    void Create();

    //void Create(const unsigned int &type);

    ~Form();
};

#endif
