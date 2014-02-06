#include "canvas.h"

Canvas::Canvas(int width, int height) : _width(width), _height(height) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_rend);
}

Canvas::~Canvas() {
  SDL_Quit();
}

void Canvas::_set_color(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(_rend, r, g, b, a);
}

void Canvas::_set_color(Color color) {
  _set_color(color[0], color[1], color[2], color[3]);
}

void Canvas::_put_pixel(int x, int y) {
  SDL_RenderDrawPoint(_rend, x, y);
}

void Canvas::_put_pixel(Vec2i point) {
  _put_pixel(point[0], point[1]);
}

void Canvas::putpixel(int x, int y, int r, int g, int b, int a) {
  _set_color(r,g,b,a);
  _put_pixel(x, y);
}

void Canvas::draw_point(const Vec2i point, const Color color) {
  putpixel(point[0], point[1], color[0], color[1], color[2], color[3]);
}

void Canvas::draw_line(const Line line, const Color color) {
  Vec2i p1;
  Vec2i p2;
  _set_color(color);
  if (line[0][0] < line[0][1]) {
    p1 = line[0];
    p2 = line[1];
  } else {
    p1 = line[1];
    p2 = line[0];
  }
  int dx = p2[0] - p1[0];
  int dy = p2[1] - p1[1];
  float err = 0;
  // Line is vertical, special case
  if (dx == 0) {
    if (dy < 0) { // swap so that dy is positive
      Vec2i swap = p1;
      p1 = p2;
      p2 = swap;
    }
    for (int i = p1[1]; i <= p2[1]; i++) {
      _put_pixel(p1[0], i);
    }
    return;
  }
  // Line is not vertical, do the normal algorithm
  float derr = fabs( (float)dy / dx);
  int y = p1[1];
  for (int x = p1[0]; x < p2[0]; x++) {
    _put_pixel(x, y);
    err += derr;
    if (err >= 0.5) {
      y++;
      err--;
    }
  }
}

void Canvas::draw_circle(const Circle circle, const Color color) {
  int x = circle.radius(), y = 0;
  int radius_err = 1-x;

  _set_color(color);

  int cx = circle.center()[0];
  int cy = circle.center()[1];

  while (x >= y) {
    _put_pixel(x + cx, y + cy);
    _put_pixel(y + cx, x + cy);
    _put_pixel(-x + cx, y + cy);
    _put_pixel(-y + cx, x + cy);
    _put_pixel(-x + cx, -y + cy);
    _put_pixel(-y + cx, -x + cy);
    _put_pixel(x + cx, -y + cy);
    _put_pixel(y + cx, -x + cy);
    
    y++;
    if (radius_err < 0) {
      radius_err += 2 * y + 1;
    } else {
      x--;
      radius_err += 2 * (y-x+1);
    }
  }
}

void Canvas::draw_circle2(const Circle circle, const Color color) {
  float resolution = 0.001f;
  float x = circle.center()[0];
  float y = circle.center()[1] - circle.radius();
  float nx, ny;
  float dtheta = resolution / circle.radius();
  float mvdist = resolution;

  for (float theta = 0; theta < 2 * M_PI; theta += dtheta) {
    nx = x + cos(theta) * mvdist;
    ny = y + sin(theta) * mvdist;

    draw_line(Line(Vec2i(nx, ny), Vec2i(x, y)), color);
    x = nx;
    y = ny;
  }
}

void Canvas::draw_circle3(const Circle circle, const Color color) {
  float resolution = 0.001f;
  float x = circle.center()[0];
  float y = circle.center()[1] - circle.radius();
  float dtheta = resolution / circle.radius();
  float mvdist = resolution;

  for (float theta = 0; theta < 2 * M_PI; theta += dtheta) {

    draw_point(Vec2i(x, y), color);

    x += cos(theta) * mvdist;
    y += sin(theta) * mvdist;
  }
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
