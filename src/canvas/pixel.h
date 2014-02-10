#pragma once

#include "color.h"
#include "geometry/point.h"

class Pixel {
protected:
  Vec2i _pt;
  Color _col;
public:
  Pixel() : _pt(Vec2i()), _col(Color()) {}
  Pixel(Vec2i pt, Color col) : _pt(pt), _col(col) {}
  Pixel(int x, int y, int r, int g, int b, int a) : _pt(Vec2i(x,y)), _col(Color(r,g,b,a)) {}

  Vec2i  point() const { return _pt; }
  Vec2i& point()       { return _pt; }

  Color  color() const { return _col; }
  Color& color()       { return _col; }

  Pixel operator + (Pixel& pixel) const { return Pixel(_pt + pixel._pt, _col + pixel._col); }
  Pixel operator - (Pixel& pixel) const { return Pixel(_pt - pixel._pt, _col - pixel._col); }
  
  void operator += (Pixel& pixel)       { _pt += pixel._pt; _col += pixel._col;          }
  void operator -= (Pixel& pixel)       { _pt -= pixel._pt; _col -= pixel._col;          }
  bool operator == (Pixel& pixel)       { return _pt == pixel._pt && _col == pixel._col; }
  bool operator != (Pixel& pixel)       { return _pt != pixel._pt || _col != pixel._col; }
};
