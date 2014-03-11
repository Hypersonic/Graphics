#pragma once

#include <assert.h>
#include <math.h>
#include <string>
#include <sstream>
#include <istream>
#include "canvas/canvas.h"
#include "geometry/point.h"
#include "geometry/bezier.h"
#include "math/Mat.h"
#include "dw/MDL.h"

static const float epsilon = 0.01f; // Maximum floating point difference
static const std::string dbgfmt = "--- %25s ---\n";

namespace Tests {
  void RunAllTests();
namespace Vector {
  void RunVectorTests();
namespace TwoDee {
  void RunTwoDeeTests();
  void TestComparison(); 
  void TestAddition();
  void TestSubtraction();
  void TestNegation();
  void TestMultiplication();
  void TestLength();
  void TestDistance();
}

namespace ThreeDee {
  void RunThreeDeeTests();
  void TestComparison(); 
  void TestAddition();
  void TestSubtraction();
  void TestNegation();
  void TestMultiplication();
}

}

namespace Geometry {
  void RunGeometryTests();
  void TestBezier();
}

namespace Matrix {
  void RunMatrixTests();
  
  void TestAccessors();
  void TestClear();
  void TestComparison();
  void TestMultiplication();
}

namespace MDL {
  void RunMDLTests();

  void TestLine();
  void TestIdentity();
  void TestScale();
  void TestTranslation();
  void TestXRotation();
  void TestYRotation();
  void TestZRotation();
  
}

}

