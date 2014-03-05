#pragma once

#include <assert.h>
#include <math.h>
#include <string>
#include "debug.h"
#include "geometry/point.h"

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

namespace Matrix {
}

}

