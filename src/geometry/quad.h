#pragma once

#include <math.h>
#include "point.h"

class Quad {
protected:
  Vec2i _tl, _tr, _br, _bl;
  Vec2i _rtl, _rtr, _rbr, _rbl;
  float _rot;
public:
  Quad() : _tl(Vec2i()), _tr(Vec2i()), _br(Vec2i()), _bl(Vec2i()),
           _rtl(_tl),    _rtr(_tr),    _rbr(_br),    _rbl(_bl), _rot(0) {}
  Quad(Vec2i topleft, Vec2i topright, Vec2i bottomleft, Vec2i bottomright) :
            _tl(topleft), _tr(topright), _br(bottomright), _bl(bottomleft),
            _rtl(_tl),    _rtr(_tr),     _rbr(_br),        _rbl(_bl), _rot(0) {}

  Vec2i  operator [](int index) const { return (&_tl)[index]; }
  Vec2i& operator [](int index)       { return (&_tl)[index]; }


  void rotate(float theta); // Rotate by theta radians

};
