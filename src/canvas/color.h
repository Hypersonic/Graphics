#pragma once

class Color {
protected:
  int _r, _g, _b, _a;
public:
  Color()                           : _r(0), _g(0), _b(0), _a(0) {}
  Color(int r, int g, int b)        : _r(r), _g(g), _b(b), _a(0) {}
  Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a) {}
  int  operator [] (int index) const { return (&_r)[index]; }
  int& operator [] (int index)       { return (&_r)[index]; }
};
