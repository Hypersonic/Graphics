#pragma once

#include "point.h"
#include "math/Mat.h"

// Curve interface
class Curve {
public:
  //virtual Vec4f  operator[](const int index) const =0;
  //virtual Vec4f& operator[](const int index) =0;
  virtual void add_point(const Vec4f& pt) =0;
  virtual Mat edges() =0; 
};
