#include "quad.h"

void Quad::rotate(float theta) {
  _rot += theta;
  while (_rot > M_PI * 2) { // Shrink down _rot
    _rot -= M_PI * 2;
  }
  float cos = cosf(_rot);
  float sin = sinf(_rot);
  
  int cx = 0;
  int cy = 0;

  for (int i = 0; i < 4; i++) {
    cx += (*this)[i][0];
    cy += (*this)[i][1];
  }
  cx = cx >> 2;
  cy = cy >> 2;
  for (int i = 0; i < 4; i++) {
    int x = cx - (*this)[i][0];
    int y = cy - (*this)[i][1];

    (*this)[i+4][0] = cx + (x*cos - y*sin) + 1; // Add one because errors
    (*this)[i+4][1] = cy + (x*sin + y*cos) + 1; // Here, too
  }
}
