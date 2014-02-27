#pragma once

#include "_shapes.h"
namespace TwoDee {
class Square : public Rect {
public:
  Square(const Vec2i topleft, int length) : Rect(topleft, Vec2i(topleft[0]+length, topleft[1]+length) ) {}
  Square(Vec2i& topleft, int length) : Rect(topleft, Vec2i(length, length) + topleft) {}

  int length() const { return Line(_tl, _tr).length(); }

  int area() const { int l = length(); return l*l; }
};
}
