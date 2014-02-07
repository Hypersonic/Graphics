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

  void draw_tri(const Tri tri, const Color color); // Draw Triangle outline

  void draw_circle(const Circle circle, const Color color); // Midpoint circle algo
  void draw_circle2(const Circle circle, const Color color, float resolution=0.1f); // Circle algo based on drawing lines
  void draw_circle3(const Circle circle, const Color color, float resolution=1.0f); // Circle algo based on tracing points
  
  void draw_quad(const Quad quad, const Color color); // Draw the outline of a quad
  void draw_rect(const Rect rect, const Color color); // Draw the outline of a rect
  void draw_square(const Square square, const Color color); // Draw the outline of a square

  void render(); //render current pixels
  void clear(); // Fill with black
};
