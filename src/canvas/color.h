#pragma once

#include <vector>

class Color {
protected:
  int _r, _g, _b, _a;
public:
  Color()                           : _r(0), _g(0), _b(0), _a(0) {}
  Color(int r, int g, int b)        : _r(r), _g(g), _b(b), _a(0) {}
  Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a) {}
  int  operator [] (int index) const { return (&_r)[index]; }
  int& operator [] (int index)       { return (&_r)[index]; }

  Color operator + (const Color& color) const { return Color(_r + color._r, _g + color._g, _b + color._b, _a + color._a); }
  Color operator + (      Color& color) const { return Color(_r + color._r, _g + color._g, _b + color._b, _a + color._a); }
  Color operator - (const Color& color) const { return Color(_r - color._r, _g - color._g, _b - color._b, _a - color._a); }
  Color operator - (      Color& color) const { return Color(_r - color._r, _g - color._g, _b - color._b, _a - color._a); }

  void operator += (Color& color)       { _r += color._r; _g += color._g; _b += color._b; _a += color._a;              }
  void operator -= (Color& color)       { _r -= color._r; _g -= color._g; _b -= color._b; _a -= color._a;              }
  bool operator == (Color& color) const { return _r == color._r && _b == color._b && _g == color._g && _a == color._a; }
  bool operator != (Color& color) const { return _r != color._r || _b != color._b || _g != color._g || _a != color._a; }

  std::vector<Color> interpolate(const Color& other, int steps) const;
};
