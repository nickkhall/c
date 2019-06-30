#ifndef FORM_H
#define FORM_H

#include <string>

#include "./window.hpp"

class Form : public Window {
  public:
    Form();

    void CollectInfo();

    //void Create(const unsigned int &type);

    ~Form();
};

#endif
