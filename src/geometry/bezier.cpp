#include "bezier.h"

Mat BezierCurve::edges() {
  Mat res;
  float step = 1.0f / Settings::resolution;
  for (float t = 0; t < 1; t += step) {
    Vec4f pt1 = BezierCurve::bezier(t       , _pts.begin(), _pts.end()-1);
    Vec4f pt2 = BezierCurve::bezier(t + step, _pts.begin(), _pts.end()-1);
    res.addCol(pt1);
    res.addCol(pt2);
  }
  
  return res;
}

Vec4f BezierCurve::bezier(float t, std::vector<Vec4f>::iterator lower, std::vector<Vec4f>::iterator upper) {
  // Base case
  if (lower == upper) {
    return *lower;
  } else {
    return (BezierCurve::bezier(t, lower, upper-1) * (1-t)) + (BezierCurve::bezier(t, lower+1, upper) * t);
  }
}

