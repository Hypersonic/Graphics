#pragma once

#include "_shapes.h"

namespace TwoDee {
class Rect : public Quad {
public:
  Rect(const Vec2i topleft, const Vec2i bottomright) :
    Quad(topleft, Vec2i(bottomright[0], topleft[1]), Vec2i(topleft[0], bottomright[1]), bottomright) {}
  Rect(Vec2i& topleft, Vec2i& bottomright) :
    Quad(topleft, Vec2i(bottomright[0], topleft[1]), Vec2i(topleft[0], bottomright[1]), bottomright) {}

  int area() { return _tl.dist(_tr)*_tl.dist(_bl); }
};
}
