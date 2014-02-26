#pragma once

#include <vector>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "debug.h"

class Line {
protected:
  Vec2i _p1, _p2, _rp1, _rp2;
  float _rot;
public:
  Line() : _p1(Vec2i()), _p2(Vec2i()), _rp1(_p1), _rp2(_p2), _rot(0) {}
  Line(const Vec2i p1, const Vec2i p2) : _p1(p1), _p2(p2), _rp1(p1), _rp2(p2), _rot(0) {}
  Line(Vec2i& p1, Vec2i& p2) : _p1(p1), _p2(p2), _rp1(p1), _rp2(p2), _rot(0) {}

  Vec2i  operator [](int index) const { return (&_p1)[index]; }
  Vec2i& operator [](int index)       { return (&_p1)[index]; }

  double length  () { return _p1.dist(_p2);  }
  int    length2 () { return _p1.dist2(_p2); }

  std::vector<Vec2i> points () const; // Get all the points that should be included in the raster of this line
                                // Based on Bresenham's Algorithm
  void rotate(float theta); // Rotate about the midpoint by theta
};
