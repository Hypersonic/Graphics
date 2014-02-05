#include "canvas.h"

Canvas::Canvas(int width, int height) : _width(width), _height(height) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_rend);
}

Canvas::~Canvas() {
  SDL_Quit();
}

void Canvas::putpixel(int x, int y, int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(_rend, r, g, b, a);
  SDL_RenderDrawPoint(_rend, x, y);
}

void Canvas::draw_point(const Vec2i point, const Color color) {
  putpixel(point[0], point[1], color[0], color[1], color[2], color[3]);
}

void Canvas::render() {
  SDL_RenderPresent(_rend);
}

void Canvas::clear() {
  for (int i = 0; i < _width; i++) {
    for (int j = 0; j < _height; j++) {
      putpixel(i, j, 0, 0, 0, 255); // Put black everywhere
    }
  }
}
