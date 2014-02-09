#include "line.h"

std::vector<Vec2i> Line::points() const {
  std::vector<Vec2i> pts = std::vector<Vec2i>();
  Vec2i p1;
  Vec2i p2;
  if (_p1[0] < _p2[0]) {
    p1 = _p1;
    p2 = _p2;
  } else {
    p1 = _p2;
    p2 = _p1;
  }
  int dx = p2[0] - p1[0];
  int dy = p2[1] - p1[1];
  float err = 0;
  // Line is vertical, special case
  if (dx == 0) {
    if (dy < 0) { // swap so that dy is positive
      Vec2i swap = p1;
      p1 = p2;
      p2 = swap;
    }
    for (int i = p1[1]; i < p2[1]; i++) {
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
      }
      while (err >= 0.5) {
        pts.push_back(Vec2i(x, y));
        y += dir;
        err--;
      }
    }
  }
  return pts;
}
