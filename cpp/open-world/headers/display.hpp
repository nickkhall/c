#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>

// Libraries
#include <SDL2/SDL.h>

class Display {
  public:
    Display(int width, int height, const std::string &title);

    void Update();
    void Clear(float r, float g, float b, float a);
    bool IsClosed() { return is_closed; };
    virtual ~Display();

  private:
    Display(const Display &other) {};
    Display &operator=(const Display &other) {};
    
    SDL_Window *window;
    SDL_GLContext gl_context;

    bool is_closed;
};

#endif
