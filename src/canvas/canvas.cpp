#include "canvas.h"

Canvas::Canvas(int width, int height) : _width(width), _height(height) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_rend);

  _img = reinterpret_cast<Pixel*>(valloc(_width * _height * sizeof(Pixel)));

  // Fill the screen with black
  _set_color(0, 0, 0, 255);
  for (int i = 0; i < _width; i++) {
    for (int j = 0; j < _height; j++) {
        _put_pixel(i, j);
    }
  }
}

Canvas::~Canvas() {
  free(_img);
  SDL_Quit();
}

void Canvas::set_title(const char* title) {
  SDL_SetWindowTitle(_window, title);
}

Pixel Canvas::_get_pixel(int x, int y) {
  return _img[y * _width + x];
}

void Canvas::_set_color(int r, int g, int b, int a) {
  _set_color(Color(r, g, b, a));
}

void Canvas::_set_color(Color color) {
  SDL_SetRenderDrawColor(_rend, color[0], color[1], color[2], color[3]);
  _col = color;
}

void Canvas::_put_pixel(int x, int y, bool draw) {
  _put_pixel(Vec2i(x, y), draw);
}

void Canvas::_put_pixel(Vec2i point, bool draw) {
  // Check if in bounds
  // TODO: Don't do this. figure this out before generating the points on a line
  if (point[0] < 0 || point[0] >= _width ||
      point[1] < 0 || point[1] >= _height) return;

  Pixel p = Pixel(point, _col);

  if (_img[point[1] * _width + point[0]] != p) {
    if (draw) {
      SDL_RenderDrawPoint(_rend, point[0], point[1]);
    }
    _img[point[1] * _width + point[0]] = p;
  }
}

void Canvas::putpixel(const Pixel pixel) {
  _set_color(pixel.color());
  _put_pixel(pixel.point());
}

void Canvas::putpixel(int x, int y, int r, int g, int b, int a) {
  _set_color(r, g, b, a);
  _put_pixel(x, y);
}

void Canvas::draw_point(const Vec2i point, const Color color) {
  putpixel(point[0], point[1], color[0], color[1], color[2], color[3]);
}

void Canvas::draw_matrix(Mat& mat, Color color) {
  _set_color(color);
  for (int i = 0; i < mat.cols(); i += 2) { // Draw pairs, so increment by 2
    std::vector<Vec2i> pts = TwoDee::Line(Vec2i(floorf(mat.get(0,i  )), floorf(mat.get(1,i  ))),
                                          Vec2i(floorf(mat.get(0,i+1)), floorf(mat.get(1,i+1)))).points();

    for (size_t j = 0; j < pts.size(); j++) {
      _put_pixel(pts[j]);
    }
  }
}

void Canvas::draw_line(const TwoDee::Line line, const Color color) {
  _set_color(color);
  std::vector<Vec2i> pts = line.points();
  for (size_t i = 0; i < pts.size(); i++) {
    _put_pixel(pts[i]);
  }
}

// TODO(Josh): Make this not shit.
void Canvas::draw_line_AA(const TwoDee::Line line, const Color color) {
  _set_color(color);
  std::vector<Vec2i> pts = line.points();
  Vec2i perp = (pts[0] - pts[pts.size()-1]).perp();
  for (size_t i = 0; i < pts.size(); i++) {
    for (int k = 1; k < 5; k++) {
      Color col2 = color;
      perp = perp.norm(k+.5f);
      for (int j = 0; j < 3; j++) {
        col2[j] = (col2[j] >> 1) - (pow(k, 5));
        col2[j] = col2[j] >= 0 ? col2[j] : 0;
      }
      _set_color(col2);
      _put_pixel(pts[i] + perp);
      _put_pixel(pts[i] - perp);
    }
    _set_color(color);
    _put_pixel(pts[i]);
  }
}

void Canvas::draw_line(const TwoDee::Line line, const std::vector<Color> colors) {
  std::vector<Vec2i> pts = line.points();
  float step = static_cast<float>(colors.size()) / pts.size();
  for (size_t i = 0; i < pts.size(); i++) {
    _set_color(colors[i * step]);
    _put_pixel(pts[i]);
  }
}

void Canvas::draw_tri(const TwoDee::Tri tri, const Color color) {
  for (int i = 0; i < 3; i++) {
    draw_line(TwoDee::Line(tri[i], tri[(i+1)%3]), color);
  }
}

void Canvas::draw_circle(const TwoDee::Circle circle, const Color color) {
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

void Canvas::draw_circle2(const TwoDee::Circle circle, \
                          const Color color,   \
                          float resolution) {
  float x = circle.center()[0];
  float y = circle.center()[1] - circle.radius();
  float nx, ny;
  float dtheta = resolution / circle.radius();
  float mvdist = resolution;

  for (float theta = 0; theta < 2 * M_PI; theta += dtheta) {
    nx = x + cos(theta) * mvdist;
    ny = y + sin(theta) * mvdist;
    draw_line(TwoDee::Line(Vec2i(nx, ny), Vec2i(x, y)), color);
    x = nx;
    y = ny;
  }
}

void Canvas::draw_circle3(const TwoDee::Circle circle, const Color color, float resolution) {
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

void Canvas::draw_quad(const TwoDee::Quad quad, const Color color) {
  for (int i = 0; i < 4; i++) {
    draw_line(TwoDee::Line(quad[i+4], quad[(i+1)%4 + 4]), color);
  }
}

void Canvas::draw_rect(const TwoDee::Rect rect, const Color color) {
  // Wrap the draw_quad function, though we can do optimizations to this later if need be.
  draw_quad(rect, color);
}

void Canvas::draw_square(const TwoDee::Square square, const Color color) {
  // Wrap the draw_rect function, though we can optimize later if needed
  draw_rect(square, color);
}

void Canvas::render() {
  SDL_RenderPresent(_rend);
}

void Canvas::clear() {
  _set_color(0, 0, 0, 255);
  Color black = Color(0, 0, 0);
  for (int i = 0; i < _width; i++) {
    for (int j = 0; j < _height; j++) {
      if (_get_pixel(i, j).color() != black) { //Only change non-black pixels
        _put_pixel(i, j, false);
      }
    }
  }
  SDL_RenderClear(_rend);
}

void Canvas::saveCurrImage() {
  FILE * file = fopen("img.ppm", "w");

  // Write PPM header
  fputs("P3\n", file); // PPM File type
  fprintf(file, "%d %d\n", _width, _height); // Width and height specifiers
  fputs("255\n", file); // Bits per pixel
  // Done with header
  for (int j = 0; j < _height; j++) {
    for (int i = 0; i < _width; i++) {
      Pixel p = _get_pixel(i, j);
      Color c = p.color();
      fprintf(file, "%d %d %d", c[0], c[1], c[2]);
      if (i != _width - 1) {
        putc(' ', file);
      }
    }
    fputc('\n', file);
  }
}
