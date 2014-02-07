#pragma once

#include "_shapes.h"

class Square : public Rect {
protected:
  const int _length;
public:
  Square(Vec2i topleft, int length) : Rect(topleft, Vec2i(length, length) + topleft), _length(length) {}

  int length() const { return _length; }
};
