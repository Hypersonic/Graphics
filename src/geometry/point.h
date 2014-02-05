#pragma once
#include <math.h>
/*
 * With thanks to http://vis.cs.brown.edu/resources/doc/gluebase-2.0/point2i_8H-source.html for reference
 */

class Vec2i {
protected:
  int _x, _y;
public:
  Vec2i() : _x(0), _y(0) {}
  Vec2i(int val1, int val2) : _x(val1), _y(val2) {}

  Vec2i operator + (Vec2i &vec) const { return Vec2i(_x+vec._x, _y+vec._y); }
  Vec2i operator - (Vec2i &vec) const { return Vec2i(_x-vec._x, _y-vec._y); }
  int   operator * (Vec2i &vec) const { return _x*vec._x + _y*vec._y;       }
  Vec2i operator - ()           const { return Vec2i(-_x, -_y);             }

  int  operator [](int index) const { return (&_x)[index]; }
  int& operator [](int index)       { return (&_x)[index]; }

  void operator += (Vec2i &vec)       { _x += vec._x; _y += vec._y;          }
  void operator -= (Vec2i &vec)       { _x -= vec._x; _y -= vec._y;          }
  bool operator == (Vec2i &vec) const { return _x == vec._x && _y == vec._y; }
  bool operator != (Vec2i &vec) const { return _x != vec._x && _y != vec._y; }

  double length  () const { return sqrt((double)_x*_x+_y*_y); }
  int    length2 () const { return _x*_x+_y*_y;               }

  double dist  (Vec2i &vec) const { return (*this-vec).length();  }
  double dist2 (Vec2i &vec) const { return (*this-vec).length2(); }

};

