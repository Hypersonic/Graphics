#pragma once

#include "_shapes.h"

class Square : public Rect {
public:
  Square(Vec2i topleft, int length) : Rect(topleft, Vec2i(length, length) + topleft) {}

  int length() const { return Line(_tl, _tr).length(); }
};
