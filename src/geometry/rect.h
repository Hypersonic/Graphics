#pragma once

#include "_shapes.h"

class Rect : public Quad {
public:
  Rect(Vec2i topleft, Vec2i bottomright) :
    Quad(topleft, Vec2i(bottomright[0], topleft[1]), Vec2i(topleft[0], bottomright[1]), bottomright) {}
};
