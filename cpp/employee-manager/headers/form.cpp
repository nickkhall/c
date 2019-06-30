#ifndef FORM_H
#define FORM_H

#include "./window.hpp"

class Form : public Window {
  public:
    Form();

    void RenderForm();

    ~Form();
};

#endif
