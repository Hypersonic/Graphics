#pragma once

#include <SDL2/SDL.h>
#include <math.h>
#include "color.h"
#include "geometry/_shapes.h"

class Canvas {
friend class Color;
private:
  void _set_color(int r, int g, int b, int a);
  void _set_color(Color color);
  void _put_pixel(int x, int y);
  void _put_pixel(Vec2i point);
protected:
  int _width, _height;
  SDL_Window* _window;
  SDL_Renderer* _rend;
public:
  Canvas(int width, int height);
  ~Canvas();
  void putpixel(int x, int y, int r, int g, int b, int a); // put a pixel at a point, make sure to call render to display
  void draw_point(const Vec2i point, const Color color);
  void draw_line(const Line line, const Color color); //Bresenham's line algo, AKA: no AA
  void draw_circle(const Circle circle, const Color color);
  void render(); //render current pixels
  void clear(); // Fill with black
};
