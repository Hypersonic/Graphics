#include "color.h"

std::vector<Color> Color::interpolate(const Color& other, int steps) const {
  Color c = other - *this;
  c._r /= steps;
  c._g /= steps;
  c._b /= steps;
  c._a /= steps;
  std::vector<Color> cols = std::vector<Color>(steps);
  for (int i = 0; i < steps; i++) {
    cols.push_back(*this + c);
  }
  return cols;
}
