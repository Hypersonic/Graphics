#pragma once

#include "point.h"

namespace TwoDee {
class Circle {
protected:
  Vec2i _center;
  int _radius;
public:
  Circle() : _center(Vec2i()), _radius(1) {}
  Circle(const Vec2i center, int radius) : _center(center), _radius(radius) {}
  Circle(Vec2i& center, int radius) : _center(center), _radius(radius) {}

  int  radius () const { return _radius;  }
  int& radius ()       { return _radius; }

  Vec2i  center () const { return _center;  }
  Vec2i& center ()       { return _center; }
};
}

// 3d circle
class Circle {
protected:
  Vec4f _center;
  int _radius;
  float _theta, _phi;
public:
  Circle() : _center(Vec4f()), _radius(1) {}
  Circle(const Vec4f center, int radius, float theta=0, float phi=0) 
          : _center(center), _radius(radius), _theta(theta), _phi(phi) {}
  Circle(Vec4f& center, int radius, float theta=0, float phi=0)
          : _center(center), _radius(radius), _theta(theta), _phi(phi) {}

  int  radius () const { return _radius;  }
  int& radius ()       { return _radius;  }

  float  theta () const { return _theta; }
  float& theta ()       { return _theta; }

  float  phi () const { return _phi; }
  float& phi ()       { return _phi; }

  Vec4f  center () const { return _center;  }
  Vec4f& center ()       { return _center; }
};
