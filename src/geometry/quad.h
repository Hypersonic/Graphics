#pragma once

#include "_shapes.h"

class Quad {
protected:
  Vec2i _tl, _tr, _bl, _br;
public:
  Quad() : _tl(Vec2i()), _tr(Vec2i()), _bl(Vec2i()), _br(Vec2i()) {}
  Quad(Vec2i topleft, Vec2i topright, Vec2i bottomleft, Vec2i bottomright) : _tl(topleft), _tr(topright), _bl(bottomleft), _br(bottomright) {}

  Vec2i  operator [](int index) const { return (&_tl)[index]; }
  Vec2i& operator [](int index)       { return (&_tl)[index]; }

};

