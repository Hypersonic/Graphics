#include "line.h"

std::vector<Vec2i> TwoDee::Line::points() const {
  int maxdist = abs((_rp1[0] - _rp2[0]) | (_rp1[1] - _rp2[1])); // This should probably be big enough to hold the points.
  std::vector<Vec2i> pts = std::vector<Vec2i>();
  pts.reserve(maxdist);
  Vec2i p1;
  Vec2i p2;
  if (_rp1[0] < _rp2[0]) {
    p1 = _rp1;
    p2 = _rp2;
  } else {
    p1 = _rp2;
    p2 = _rp1;
  }
  int dx = p2[0] - p1[0];
  int dy = p2[1] - p1[1];
  float err = 0;
  // Line is vertical, special case
  if (dx == 0) {
    if (dy < 0) { // swap so that dy is positive
      std::swap(p1, p2);
    }
    for (int i = p1[1]; i <= p2[1]; i++) {
      pts.push_back(Vec2i(p1[0], i));
    }
  } else {
    // Line is not vertical, do the normal algorithm
    float derr = fabs( (float)dy / dx);
    int y = p1[1];
    int dir = derr / ((float)dy/dx); // Figure out whether to move y up or down
    for (int x = p1[0]; x < p2[0]; x++) {
      err += derr;
      if (err < 0.5) {
        pts.push_back(Vec2i(x, y));
      } else {
        while (err >= 0.5) {
          pts.push_back(Vec2i(x, y));
          y += dir;
          err--;
        }
      }
    }
  }
  return pts;
}

void TwoDee::Line::rotate(float theta) {
  _rot += theta;

  while (_rot > M_PI * 2) { // Shrink down _rot
    _rot -= M_PI * 2;
  }

  float cos = cosf(_rot);
  float sin = sinf(_rot);

  int cx = 0;
  int cy = 0;

  // Sum the coords
  for (int i = 0; i < 2; i++) {
    cx += (*this)[i][0];
    cy += (*this)[i][1];
  }
  // Divide both coords by 2 to get the avg.
  cx = cx >> 1;
  cy = cy >> 1;
  for (int i = 0; i < 2; i++) {
    int x = cx - (*this)[i][0];
    int y = cy - (*this)[i][1];

    (*this)[i+2][0] = cx + (x*cos - y*sin) + 1; // Add one because errors
    (*this)[i+2][1] = cy + (x*sin + y*cos) + 1; // Here, too
  }
}
