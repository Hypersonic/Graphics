#pragma once

#include <vector>
#include <stdlib.h>
#include "point.h"

class Line {
protected:
  Vec2i _p1, _p2;
public:
  Line() : _p1(Vec2i()), _p2(Vec2i()) {}
  Line(Vec2i p1, Vec2i p2) : _p1(p1), _p2(p2) {}

  Vec2i  operator [](int index) const { return (&_p1)[index]; }
  Vec2i& operator [](int index)       { return (&_p1)[index]; }

  double length  () { return _p1.dist(_p2);  }
  int    length2 () { return _p1.dist2(_p2); }

  std::vector<Vec2i> points () const; // Get all the points that should be included in the raster of this line
                                // Based on Bresenham's Algorithm
};
