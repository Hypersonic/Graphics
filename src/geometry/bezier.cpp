#include "bezier.h"

Mat BezierCurve::edges() {
  Mat res;
  float step = 1.0f / Settings::resolution;
  res.reserve(2.0f/step);
  for (float t = 0; t < 1; t += step) {
    Vec4f pt1 = BezierCurve::bezier(t       , _pts.begin(), _pts.end()-1);
    Vec4f pt2 = BezierCurve::bezier(t + step, _pts.begin(), _pts.end()-1);
    // Set the final value to 1, so transforms work properly
    pt1[3] = 1;
    pt2[3] = 1;
    // Put them in our matrix
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
