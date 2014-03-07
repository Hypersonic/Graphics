#include "test.h"

using namespace Tests;

void Vector::TwoDee::TestComparison() {
  printf(dbgfmt.c_str(), "Testing Comparisons");
  Vec2i first, second;

  // Test equality
  first  = Vec2i(10, 10);
  second = Vec2i(10, 10);
  assert(first == second);
  
  // Test X inequality
  first  = Vec2i(11, 4);
  second = Vec2i(10, 4);
  assert(first != second);

  // Test Y inequality
  first  = Vec2i(2, 7);
  second = Vec2i(2, 9);
  assert(first != second);

  // Test XY inequality
  first  = Vec2i(1, 3);
  second = Vec2i(4, 1);
  assert(first != second);
}

void Vector::TwoDee::TestAddition() {
  printf(dbgfmt.c_str(), "Testing Addition");
  Vec2i first, second, result, expected;

  first  = Vec2i(1, 1);
  second = Vec2i(4, 5);

  result = first + second;

  expected = Vec2i(5, 6);

  assert(result == expected);
  
  // Test the in place operator
  first += second;

  assert(first == expected);
}

void Vector::TwoDee::TestSubtraction() {
  printf(dbgfmt.c_str(), "Testing Subtraction");
  Vec2i first, second, result, expected;

  first  = Vec2i(1, 1);
  second = Vec2i(4, 5);

  result = first - second;

  expected = Vec2i(-3, -4);

  assert(result == expected);
  
  // Test the in place operator
  first -= second;

  assert(first == expected);

}

void Vector::TwoDee::TestNegation() {
  printf(dbgfmt.c_str(), "Testing Negation");
  Vec2i first, result, expected;

  first = Vec2i(10, 22);

  expected = Vec2i(-10, -22);

  result = -first;

  assert(result == expected);
}

void Vector::TwoDee::TestMultiplication() {
  printf(dbgfmt.c_str(), "Testing Multiplication");
  int result, expected;
  Vec2i first, second;

  first  = Vec2i(24, 3);
  second = Vec2i(2, 25);

  expected = (2 * 24) + (3 * 25);

  result = first * second;

  assert(result == expected);
}

void Vector::TwoDee::TestLength() {
  printf(dbgfmt.c_str(), "Testing Length");
  float actual, expected;
  Vec2i test;
  test = Vec2i(10, 10);

  actual = test.length();

  expected = 14.14; // sqrt(10^2 + 10^2), estimated

  assert(fabs(expected - actual) < epsilon);
}

void Vector::TwoDee::TestDistance() {
  printf(dbgfmt.c_str(), "Testing Distance");
  Vec2i first, second;
  float actual, expected;

  first  = Vec2i(10, 10);
  second = Vec2i(9 ,  9);

  actual = second.dist(first);

  expected = 1.41f;

  assert(fabs(actual - expected) < epsilon);

}

void Vector::ThreeDee::TestComparison() {
  printf(dbgfmt.c_str(), "Testing Comparisons");
  Vec4f first, second;

  // Test Equality
  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(1, 2, 3, 4);

  assert(first == second);

  // Test first value inequality
  first  = Vec4f(0, 2, 3, 4);
  second = Vec4f(1, 2, 3, 4);

  assert(first != second);
  
  // Test second value inequality
  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(1, 0, 3, 4);

  assert(first != second);

  // Test third value inequality
  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(1, 2, 0, 4);

  assert(first != second);

  // Test fourth value inequality
  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(1, 2, 3, 0);

  assert(first != second);

  // Test complete inequality
  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(2, 3, 4, 5);
  
  assert(first != second);
}

void Vector::ThreeDee::TestAddition() {
  printf(dbgfmt.c_str(), "Testing Addition");
  Vec4f first, second, actual, expected;

  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(3, 2, 1, 9);

  expected = Vec4f(4, 4, 4, 13);

  actual = first + second;

  assert(expected == actual);
}

void Vector::ThreeDee::TestSubtraction() {
  printf(dbgfmt.c_str(), "Testing Subtraction");
  Vec4f first, second, actual, expected;

  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(3, 2, 1, 9);

  expected = Vec4f(-2, 0, 2, -5);

  actual = first - second;

  assert(expected == actual);
}

void Vector::ThreeDee::TestNegation() {
  printf(dbgfmt.c_str(), "Testing Negation");
  Vec4f first, actual, expected;

  first = Vec4f(10, 10, 10, 10);

  expected = Vec4f(-10, -10, -10, -10);

  actual = -first;

  assert(actual == expected);
}

void Vector::ThreeDee::TestMultiplication() {
  printf(dbgfmt.c_str(), "Testing Multiplication");
  Vec4f first, second;
  float actual, expected;

  first  = Vec4f(1, 2, 3, 4);
  second = Vec4f(2, 3, 4, 5);

  expected = 40.0f;

  actual = first * second;

  assert(abs(expected - actual) < epsilon);
}

void Matrix::TestAccessors() {
  Vec4f expected;
  printf(dbgfmt.c_str(), "Testing Accessor Methods");
  Mat m = Mat();

  m.addCol(Vec4f(1 , 2 , 3 , 4 ));
  m.addCol(Vec4f(5 , 6 , 7 , 8 ));
  m.addCol(Vec4f(9 , 10, 11, 12));
  m.addCol(Vec4f(13, 14, 15, 16));


  // Test .get(row, col)
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      assert(fabs(m.get(i,j) - ((4*j) + i + 1)) < epsilon);
    }
  }

  // Test .getRow(row)
  Vec4f row = m.getRow(3);
  expected = Vec4f(4, 8, 12, 16);
  assert(row == expected);

  // Test .getCol(col)
  Vec4f col = m.getCol(1);
  expected = Vec4f(5, 6, 7, 8);
  assert(col == expected);
}

void Matrix::TestClear() {
  Mat m;
  printf(dbgfmt.c_str(), "Testing Clear");

  m.addCol(Vec4f(1, 2, 3, 4));
  assert(m.cols() > 0); // Make sure we start with something in the matrix

  m.clear();

  assert(m.cols() == 0); // Test that we are back to a blank matrix
}

void Matrix::TestComparison() {
  Mat first, second;
  printf(dbgfmt.c_str(), "Testing Comparison");

  // Test identical, 1 collum matrices
  first .addCol(Vec4f(1, 2, 3, 4));
  second.addCol(Vec4f(1, 2, 3, 4));

  assert(first == second);

  // Wipe them
  first.clear();
  second.clear();

  // Test identical, multi-collum matrices
  first .addCol(Vec4f(1, 2, 3, 4));
  first .addCol(Vec4f(3, 4, 5, 6));
  second.addCol(Vec4f(1, 2, 3, 4));
  second.addCol(Vec4f(3, 4, 5, 6));

  assert(first == second);

  // Wipe them
  first.clear();
  second.clear();

  // Test different, single collum matrices
  first .addCol(Vec4f(1, 2, 3, 4));
  second.addCol(Vec4f(2, 3, 4, 5));

  assert(first != second);

  // Wipe them
  first.clear();
  second.clear();

  // Test different, multi-collum matrices
  first .addCol(Vec4f(1, 2, 3, 4));
  first .addCol(Vec4f(4, 5, 6, 8));
  second.addCol(Vec4f(3, 4, 5, 6));
  second.addCol(Vec4f(4, 5, 6, 8)); // note that this is the same as the second col on the other matrix, in order to ensure that the matrices are being fully compared

  assert(first != second);
}

void Matrix::TestMultiplication() {
  Mat m1, m2, actual, expected;
  printf(dbgfmt.c_str(), "Testing Multiplication");

  // Test same sized matrices
  /*
   *  [ 1 2 3 4 ]       [ 4 5 6 7 ]
   *  [ 2 3 4 5 ]       [ 3 4 5 6 ]
   *  [ 3 4 5 6 ]   *   [ 2 3 4 5 ]
   *  [ 4 5 6 7 ]       [ 1 2 3 4 ]
   *
   *  Should come out to..
   *
   *  [ 20 30 40 50  ]
   *  [ 30 44 58 72  ]
   *  [ 40 58 76 94  ]
   *  [ 50 72 94 116 ]
   */
  m1.addCol(Vec4f(1, 2, 3, 4));
  m1.addCol(Vec4f(2, 3, 4, 5));
  m1.addCol(Vec4f(3, 4, 5, 6));
  m1.addCol(Vec4f(4, 5, 6, 7));

  m2.addCol(Vec4f(4, 3, 2, 1));
  m2.addCol(Vec4f(5, 4, 3, 2));
  m2.addCol(Vec4f(6, 5, 4, 3));
  m2.addCol(Vec4f(7, 6, 5, 4));

  expected.addCol(Vec4f(20, 30, 40, 50));
  expected.addCol(Vec4f(30, 44, 58, 72));
  expected.addCol(Vec4f(40, 58, 76, 94));
  expected.addCol(Vec4f(50, 72, 94, 116));

  actual = m1.multiply(m2);

  assert(actual == expected);
  
  // Clear everything
  m1.clear();
  m2.clear();
  actual.clear();
  expected.clear();

  // Try multiplying mats of different size
  /*
   *  [ 1 2 3 4 ]       [ 4 5 6 ]
   *  [ 2 3 4 5 ]       [ 3 4 5 ]
   *  [ 3 4 5 6 ]   *   [ 2 3 4 ]
   *  [ 4 5 6 7 ]       [ 1 2 3 ]
   *
   *  Should come out to..
   *
   *  [ 20 30 40 ]
   *  [ 30 44 58 ]
   *  [ 40 58 76 ]
   *  [ 50 72 94 ]
   */

  m1.addCol(Vec4f(1, 2, 3, 4));
  m1.addCol(Vec4f(2, 3, 4, 5));
  m1.addCol(Vec4f(3, 4, 5, 6));
  m1.addCol(Vec4f(4, 5, 6, 7));

  m2.addCol(Vec4f(4, 3, 2, 1));
  m2.addCol(Vec4f(5, 4, 3, 2));
  m2.addCol(Vec4f(6, 5, 4, 3));

  expected.addCol(Vec4f(20, 30, 40, 50));
  expected.addCol(Vec4f(30, 44, 58, 72));
  expected.addCol(Vec4f(40, 58, 76, 94));

  actual = m1.multiply(m2);

  assert(actual == expected);
}

void MDL::TestLine() {
  printf(dbgfmt.c_str(), "Line Test");
  Mat pts, trans;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "l\n0 0 0 100 100 100"; // Create a line from (0,0,0) to (100,100,100)
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  MDLParser::ParseCmd(stream, can, pts, trans);
  Vec4f expected;
  expected = Vec4f(0,0,0,1);
  assert(pts.getCol(0) == expected);
  expected = Vec4f(100,100,100,1);
  assert(pts.getCol(1) == expected);
}

void MDL::TestIdentity() {
  printf(dbgfmt.c_str(), "Testing Identity Matrix");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "i"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  // Fill trans with some junk
  trans.addCol(Vec4f(1,2,3,4));
  trans.addCol(Vec4f(1,2,3,4));
  trans.addCol(Vec4f(1,2,3,4));
  trans.addCol(Vec4f(1,2,3,4));

  // Run our function
  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::Identity();

  assert(trans == expected);
}

void MDL::TestScale() {
  printf(dbgfmt.c_str(), "Testing Scaling");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "s\n1 2 3"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  trans = Mat::Identity(); // Initialize our transform to the identity matrix

  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::ScaleMat(1, 2, 3);
  
  assert(trans == expected);
}

void MDL::TestTranslation() {
  printf(dbgfmt.c_str(), "Testing Translation");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "t\n100 20 3"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  trans = Mat::Identity(); // Initialize our transform to the identity matrix

  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::TransMat(100, 20, 3);
  
  assert(trans == expected);
}

void MDL::TestXRotation() {
  printf(dbgfmt.c_str(), "Testing X Rotation");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "x\n10"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  trans = Mat::Identity(); // Initialize our transform to the identity matrix

  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::XRotMat((10 * 180) / M_PI);
  
  assert(trans == expected);
}

void MDL::TestYRotation() {
  printf(dbgfmt.c_str(), "Testing Y Rotation");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "y\n10"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  trans = Mat::Identity(); // Initialize our transform to the identity matrix

  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::YRotMat((10 * 180) / M_PI);
  
  assert(trans == expected);
}

void MDL::TestZRotation() {
  printf(dbgfmt.c_str(), "Testing Z Rotation");
  Mat pts, trans, expected;
  Canvas can = Canvas(640, 480, true);
  std::string cmd = "z\n10"; // Ask for trans to be set to an identity matrix
  std::stringbuf buf;
  std::istream stream (&buf); // Create an istream containing our buffer
  buf.str(cmd);

  trans = Mat::Identity(); // Initialize our transform to the identity matrix

  MDLParser::ParseCmd(stream, can, pts, trans);
  expected = Mat::ZRotMat((10 * 180) / M_PI);
  
  assert(trans == expected);
}

void Tests::RunAllTests() {
  printf(dbgfmt.c_str(), "Starting Tests");
  Vector::RunVectorTests();
  Matrix::RunMatrixTests();
  MDL::RunMDLTests();
  printf(dbgfmt.c_str(), "All Tests Passed");
}

void Vector::RunVectorTests() {
  printf(dbgfmt.c_str(), "Vector Tests");
  TwoDee::RunTwoDeeTests();
  ThreeDee::RunThreeDeeTests();
}

void Vector::TwoDee::RunTwoDeeTests() {
  printf(dbgfmt.c_str(), "2D Vector Tests");
  using namespace Tests::Vector::TwoDee;
  TestComparison();
  TestAddition();
  TestSubtraction();
  TestNegation();
  TestMultiplication();
  TestLength();
  TestDistance();
}

void Vector::ThreeDee::RunThreeDeeTests() {
  printf(dbgfmt.c_str(), "3D Vector Tests");
  using namespace Tests::Vector::ThreeDee;
  TestComparison();
  TestAddition();
  TestSubtraction();
  TestNegation();
  TestMultiplication();
}

void Matrix::RunMatrixTests() {
  printf(dbgfmt.c_str(), "Matrix Tests");
  using namespace Tests::Matrix;
  TestAccessors();
  TestClear();
  TestComparison();
  TestMultiplication();
}

void MDL::RunMDLTests() {
  printf(dbgfmt.c_str(), "MDL Tests");
  using namespace Tests::MDL;
  TestLine();
  TestIdentity();
  TestScale();
  TestTranslation();
  TestXRotation();
  TestYRotation();
  TestZRotation();
}
