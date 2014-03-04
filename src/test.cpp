#include "test.h"

using namespace Tests;

void Vector::TwoDee::TestComparison() {
  debug("--- Testing Comparisons ---\n");
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
  debug("--- Testing Addition ---\n");
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
  debug("--- Testing Subtraction ---\n");
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
  debug("--- Testing Negation ---\n");
  Vec2i first, result, expected;

  first = Vec2i(10, 22);

  expected = Vec2i(-10, -22);

  result = -first;

  assert(result == expected);
}

void Vector::TwoDee::TestMultiplication() {
  debug("--- Testing Multiplication ---\n");
  int result, expected;
  Vec2i first, second;

  first  = Vec2i(24, 3);
  second = Vec2i(2, 25);

  expected = (2 * 24) + (3 * 25);

  result = first * second;

  assert(result == expected);
}

void Vector::TwoDee::TestLength() {
  float actual, expected;
  Vec2i test;
  test = Vec2i(10, 10);

  actual = test.length();

  expected = 14.14; // sqrt(10^2 + 10^2), estimated

  assert(fabs(expected - actual) < epsilon);
}

void Vector::TwoDee::TestDistance() {
  Vec2i first, second;
  float actual, expected;

  first  = Vec2i(10, 10);
  second = Vec2i(9 ,  9);

  actual = second.dist(first);

  expected = 1.41f;

  assert(fabs(actual - expected) < epsilon);

}

void Tests::RunAllTests() {
  debug("--- Starting Tests ---\n");
  Vector::RunVectorTests();
  debug("--- All Tests Passed ---\n");
}

void Vector::RunVectorTests() {
  debug("--- Vector Tests ---\n");
  TwoDee::RunTwoDeeTests();
  ThreeDee::RunThreeDeeTests();
}

void Vector::TwoDee::RunTwoDeeTests() {
  debug("--- 2D Vector Tests ---\n");
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
  debug("--- 3D Vector Tests ---\n");
  using namespace Tests::Vector::ThreeDee;
  //TestComparison();
  //TestAddition();
  //TestSubtraction();
  //TestNegation();
  //TestMultiplication();
  //TestLength();
  //TestDistance();
}
