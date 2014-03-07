#pragma once

#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include "math/Mat.h"
#include "color.h"
#include "pixel.h"
#include "geometry/_shapes.h"
#include "debug.h"

class Canvas {
private:
  void _set_color(const int r, const int g, const int b, const int a);
  void _set_color(const Color color);
  void _put_pixel(const int x, const int y, const bool draw=true);
  void _put_pixel(const Vec2i point, const bool draw=true);
  Pixel _get_pixel(const int x, const int y) const;
protected:
  int _width, _height;
  bool _headless;
  Pixel* _img;
  Color _col;
  SDL_Window* _window;
  SDL_Renderer* _rend;
public:
  Canvas(const int width, const int height, const bool headless=false);
  ~Canvas();
  void set_title(const char* title);
  void putpixel(const Pixel pixel);
  void putpixel(const int x, const int y, const int r, const int g, const int b, const int a); // put a pixel at a point, make sure to call render to display

  void draw_point(const Vec2i point, const Color color);

  void draw_matrix(const Mat& mat, const Color color);

  void draw_line(const TwoDee::Line line, const Color color); //Bresenham's line algo, AKA: no AA
  void draw_line(const TwoDee::Line line, const std::vector<Color> color); //Bresenham's line algo, AKA: no AA
  void draw_line_AA(const TwoDee::Line line, const Color color); // crappy AntiAliasing on top of Bresenham.

  void draw_tri(const TwoDee::Tri tri, const Color color); // Draw Triangle outline

  void draw_circle(const TwoDee::Circle circle, const Color color); // Midpoint circle algo
  void draw_circle2(const TwoDee::Circle circle, const Color color, float resolution=0.1f); // Circle algo based on drawing lines
  void draw_circle3(const TwoDee::Circle circle, const Color color, float resolution=1.0f); // Circle algo based on tracing points
  
  void draw_quad(const TwoDee::Quad quad, const Color color); // Draw the outline of a quad
  void draw_rect(const TwoDee::Rect rect, const Color color); // Draw the outline of a rect
  void draw_square(const TwoDee::Square square, const Color color); // Draw the outline of a square

  void render() const; //render current pixels
  void clear(); // Fill with black

  void saveCurrImage(const char* filename) const; // save the current rendered image. Very slow, yo
};
