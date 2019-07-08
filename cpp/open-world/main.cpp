#include <iostream>
#include <GL/glew.h>

#include "headers/display.hpp"
#include "headers/shader.hpp"

int main() {
  Display display(800, 600, "Open World");
  Shader shader("./res/basic-shader");

  while (!display.IsClosed()) {
    display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
    shader.Bind();

    display.Update();
  };
  return 0;
}
