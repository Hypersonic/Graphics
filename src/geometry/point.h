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
  Vec2i(const int val1, const int val2) : _x(val1), _y(val2) {}

  Vec2i operator + (const Vec2i &vec) const { return Vec2i(_x+vec._x, _y+vec._y); }
  Vec2i operator - (const Vec2i &vec) const { return Vec2i(_x-vec._x, _y-vec._y); }
  int   operator * (const Vec2i &vec) const { return _x*vec._x + _y*vec._y;       }
  Vec2i operator - ()           const { return Vec2i(-_x, -_y);             }

  int  operator [](const int index) const { return (&_x)[index]; }
  int& operator [](const int index)       { return (&_x)[index]; }

  void operator += (const Vec2i &vec)       { _x += vec._x; _y += vec._y;          }
  void operator -= (const Vec2i &vec)       { _x -= vec._x; _y -= vec._y;          }
  bool operator == (const Vec2i &vec) const { return _x == vec._x && _y == vec._y; }
  bool operator != (const Vec2i &vec) const { return _x != vec._x || _y != vec._y; }

  float length  () const { return sqrt((float)_x*_x+_y*_y); }
  int   length2 () const { return _x*_x+_y*_y;              }

  float dist  (const Vec2i &vec) const { return (*this-vec).length();  }
  float dist2 (const Vec2i &vec) const { return (*this-vec).length2(); }

  Vec2i perp () const { return Vec2i(-_y, _x); }

  Vec2i norm (float newlen) const { return Vec2i((newlen*_x)/length(), (newlen*_y)/length()); }
};

class Vec4f {
protected:
  float _x, _y, _z, _r;
private:
  constexpr static float epsilon = .01f; // For comparing vectors
public:
  Vec4f(const float val1=0, const float val2=0, const float val3=0, const float val4=0) :
                    _x(val1), _y(val2), _z(val3), _r(val4) {}

  Vec4f operator + (const Vec4f &vec) const { return Vec4f(_x+vec._x, _y+vec._y,
                                                     _z+vec._z, _r+vec._r); }
  Vec4f operator - (const Vec4f &vec) const { return Vec4f(_x-vec._x, _y-vec._y,
                                                     _z-vec._z, _r-vec._r); }
  float operator * (const Vec4f &vec) const { return _x*vec._x + _y*vec._y +
                                               _z*vec._z + _r*vec._r;       }
  Vec4f operator - ()           const { return Vec4f(-_x, -_y, -_z, -_r);   }

  float  operator [](const int index) const { return (&_x)[index]; }
  float& operator [](const int index)       { return (&_x)[index]; }

  void operator += (const Vec4f &vec)       { _x += vec._x; _y += vec._y;
                                        _z += vec._z; _r += vec._r;          }
  void operator -= (const Vec4f &vec)       { _x -= vec._x; _y -= vec._y;
                                        _z -= vec._z; _r -= vec._r;          }
  bool operator == (const Vec4f &vec) const { return fabs(_x - vec._x) < epsilon &&
                                               fabs(_y - vec._y) < epsilon &&
                                               fabs(_z - vec._z) < epsilon &&
                                               fabs(_r - vec._r) < epsilon; }

  bool operator != (const Vec4f &vec) const { return fabs(_x - vec._x) >= epsilon ||
                                               fabs(_y - vec._y) >= epsilon ||
                                               fabs(_z - vec._z) >= epsilon ||
                                               fabs(_r - vec._r) >= epsilon; }
};
