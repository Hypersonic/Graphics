#include "bezier.h"

Mat BezierCurve::edges() {
  Mat res;
  float step = 1.0f / Settings::resolution;
  res.reserve(2.0f/step);
  for (float t = 0; t < 1-step; t += step) {
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
  //Base case
  if (lower == upper) {
    return *lower;
  } else {
    std::vector<Vec4f> pts;
    for (; lower < upper; lower++) {
      pts.push_back(*(lower)*(1-t) + *(lower+1)*(t));
    }
    return bezier(t, pts.begin(), pts.end()-1);
  }
}

