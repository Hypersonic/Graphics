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

void Tests::RunAllTests() {
  printf(dbgfmt.c_str(), "Starting Tests");
  Vector::RunVectorTests();
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
