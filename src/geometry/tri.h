#pragma once

#include "point.h"

namespace TwoDee {
class Triangle {
protected:
  Vec2i _v1, _v2, _v3;
public:
  Triangle() : _v1(Vec2i()), _v2(Vec2i()), _v3(Vec2i()) {}
  Triangle(const Vec2i v1, const Vec2i v2, const Vec2i v3) : _v1(v1), _v2(v2), _v3(v3) {}
  Triangle(Vec2i& v1, Vec2i& v2, Vec2i& v3) : _v1(v1), _v2(v2), _v3(v3) {}

  Vec2i  operator[](int index) const { return (&_v1)[index]; }
  Vec2i& operator[](int index)       { return (&_v1)[index]; }
};
typedef Triangle Tri;
}

// 3d triangle
class Triangle {
protected:
  Vec4f _v1, _v2, _v3;
public:
  Triangle() : _v1(Vec4f()), _v2(Vec4f()), _v3(Vec4f()) {}
  Triangle(const Vec4f v1, const Vec4f v2, const Vec4f v3) : _v1(v1), _v2(v2), _v3(v3) {}
  Triangle(Vec4f& v1, Vec4f& v2, Vec4f& v3) : _v1(v1), _v2(v2), _v3(v3) {}

  Vec4f  operator[](int index) const { return (&_v1)[index]; }
  Vec4f& operator[](int index)       { return (&_v1)[index]; }
};
typedef Triangle Tri;
