#include "Mat.h"

Vec4f Mat::getRow(const int row) const {
  Vec4f res_row = Vec4f();
  for (int i = 0; i < 4; i++) {
    res_row[i] = _data[i][row];
  }
  return res_row;
}

// prereqs: m1._rows == m2._rows && m1._cols == m2._cols
float Mat::dot(const Vec4f& v1, const Vec4f& v2) const {
  float res = 0;
  for (int i = 0; i < 4; i++) {
    res += v1[i] * v2[i];
  }
  return res;
}

Mat Mat::multiply(const Mat m2) const {
  Mat resultant = Mat(); // Make the resultant the correct size

  for (int i = 0; i < m2.cols(); i++) {
    resultant.addCol(Vec4f());
  }
  for (int i = 0; i < m2.cols(); i++) {
    for (int j = 0; j < 4; j++) {
      Vec4f first  = m2.getCol(i);
      Vec4f second =    getRow(j);
      resultant.get(j,i) = dot(first, second);
    }
  }
  return resultant;
}

const Mat Mat::Identity() {
  Mat res = Mat();
  res.addCol(Vec4f(1, 0, 0, 0));
  res.addCol(Vec4f(0, 1, 0, 0));
  res.addCol(Vec4f(0, 0, 1, 0));
  res.addCol(Vec4f(0, 0, 0, 1));

  return res;
}

const Mat Mat::ZRotMat(float theta) {
  float sin = sinf(theta);
  float cos = cosf(theta);
  Mat res = Mat();
  res.addCol(Vec4f(cos , sin, 0, 0));
  res.addCol(Vec4f(-sin, cos, 0, 0));
  res.addCol(Vec4f(0   ,   0, 1, 0));
  res.addCol(Vec4f(0   ,   0, 0, 1));
  return res;
}

const Mat Mat::XRotMat(float theta) {
  float sin = sinf(theta);
  float cos = cosf(theta);
  Mat res = Mat();
  res.addCol(Vec4f(1,    0,   0, 0));
  res.addCol(Vec4f(0,  cos, sin, 0));
  res.addCol(Vec4f(0, -sin, cos, 0));
  res.addCol(Vec4f(0,    0,   0, 1));
  return res;
}

const Mat Mat::YRotMat(float theta) {
  float sin = sinf(theta);
  float cos = cosf(theta);
  Mat res = Mat();
  res.addCol(Vec4f(cos ,  0,  sin, 0));
  res.addCol(Vec4f(0   ,  1,    0, 0));
  res.addCol(Vec4f(-sin,  0,  cos, 0));
  res.addCol(Vec4f(0   ,  0,    0, 1));
  return res;
}

const Mat Mat::TransMat(int x, int y, int z) {
  Mat res = Mat();
  res.addCol(Vec4f(1, 0, 0, 0));
  res.addCol(Vec4f(0, 1, 0, 0));
  res.addCol(Vec4f(0, 0, 1, 0));
  res.addCol(Vec4f(x, y, z, 1));

  return res;
}

const Mat Mat::ScaleMat(float x, float y, float z) {
  Mat res = Mat();
  res.addCol(Vec4f(x, 0, 0, 0));
  res.addCol(Vec4f(0, y, 0, 0));
  res.addCol(Vec4f(0, 0, z, 0));
  res.addCol(Vec4f(0, 0, 0, 1));

  return res;
}
