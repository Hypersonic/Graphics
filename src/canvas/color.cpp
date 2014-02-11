#include "color.h"

std::vector<Color> Color::interpolate(const Color& other, int steps) const {
  Color c = *this - other;
  c._r /= steps;
  c._g /= steps;
  c._b /= steps;
  c._a /= steps;
  std::vector<Color> cols = std::vector<Color>(steps);
  Color curr = Color(0, 0, 0);
  for (int i = 0; i < steps; i++) {
    cols.push_back(other + curr);
    curr += c;
  }
  return cols;
}
