#pragma once

#include <SDL2/SDL.h>
#include "color.h"

class Canvas {
friend class Color;
protected:
  int _width, _height;
  SDL_Window* _window;
  SDL_Renderer* _rend;
public:
  Canvas(int width, int height);
  ~Canvas();
  void putpixel(int x, int y, int r, int g, int b, int a); // put a pixel at a point, make sure to call render to display
  void render(); //render current pixels
  void clear(); // Fill with black
};
