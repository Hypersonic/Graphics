#pragma once

#include <stdlib.h>
#include <fstream>
#include <istream>
#include <string>
#include <unistd.h>

#include "geometry/point.h"
#include "canvas/canvas.h"
#include "math/Mat.h"
#include "debug.h"

namespace MDLParser {
  void ParseCmd(const char* cmd, Canvas& can, Mat& points, Mat& transform); 
  void ParseCmd(std::istream& file, Canvas& can, Mat& points, Mat& transform);
}
