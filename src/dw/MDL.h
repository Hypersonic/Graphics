#pragma once

#include <stdlib.h>
#include <fstream>
#include <string>

#include "geometry/point.h"
#include "canvas/canvas.h"
#include "math/Mat.h"
#include "debug.h"

class MDLParser {
public:
  static void ParseCmd(const char* cmd, Canvas& can, Mat& points, Mat& transform);
};
