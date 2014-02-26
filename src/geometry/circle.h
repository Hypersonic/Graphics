#pragma once

#include "point.h"

class Circle {
protected:
  Vec2i _center;
  int _radius;
public:
  Circle() : _center(Vec2i()), _radius(1) {}
  Circle(const Vec2i center, int radius) : _center(center), _radius(radius) {}
  Circle(Vec2i& center, int radius) : _center(center), _radius(radius) {}

  int  radius () const { return _radius;  }
  int& radius ()       { return _radius; }

  Vec2i  center () const { return _center;  }
  Vec2i& center ()       { return _center; }
};
