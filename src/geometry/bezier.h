#pragma once

#include <vector>
#include <map>
#include "settings.h"
#include "curve.h"
#include "point.h"

class BezierCurve : public Curve {
protected:
  std::vector<Vec4f> _pts;
public:
  BezierCurve() : _pts(std::vector<Vec4f>()) {}
  BezierCurve(std::vector<Vec4f>& pts) : _pts(pts) {}

  //Vec4f  operator[](const int index) const { return _pts[index]; }
  //Vec4f& operator[](const int index)       { return _pts[index]; }

  int num_points() { return _pts.size(); }

  std::vector<Vec4f>::iterator begin() { return _pts.begin(); }
  std::vector<Vec4f>::iterator end() { return _pts.end(); }

  void add_point(const Vec4f& pt) { _pts.push_back(pt); }

  Mat edges();

  static Vec4f bezier(float t, std::vector<Vec4f>::iterator lower, std::vector<Vec4f>::iterator upper);

};
