#pragma once

class Triangle {
protected:
  Vec2i _v1, _v2, _v3;
public:
  Triangle() : _v1(Vec2i()), _v2(Vec2i()), _v3(Vec2i()) {}
  Triangle(Vec2i v1, Vec2i v2, Vec2i v3) : _v1(v1), _v2(v2), _v3(v3) {}

  Vec2i  operator[](int index) const { return (&_v1)[index]; }
  Vec2i& operator[](int index)       { return (&_v1)[index]; }
};
typedef Triangle Tri;
