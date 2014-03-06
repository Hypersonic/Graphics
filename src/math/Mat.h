#pragma once

#include <stdlib.h>
#include <vector>

#include "geometry/point.h"
#include "debug.h"

class Mat {
protected:
  int _cols;
  std::vector<Vec4f> _data;
public:
  Mat() : _cols(0), _data(std::vector<Vec4f>()) {}
  
  int cols() const { return _cols; }

  float  get(int row, int col=0) const { return _data[col][row]; }
  float& get(int row, int col=0)       { return _data[col][row]; }

  Vec4f getRow(int row) const; // Return the requested row, assuming it has at most 4 els
  Vec4f getCol(int col) const; // Return the requested col, assuming it has at most 4 els

  void addCol(Vec4f col) { _data.push_back(col); _cols++; }

  void clear() { _data.clear(); _cols = 0; }

  float dot(const Vec4f v1, const Vec4f v2) const; // Calculate the dot product of two Vec4is
  
  Mat multiply(const Mat m2); // this * m2

  void operator *=(Mat& other) { Mat res = (*this).multiply(other); _data = res._data; _cols = res._cols; }

  bool operator ==(Mat& other) { for (int i = 0; i < _cols; i++) {
                                      Vec4f first  =       getCol(i);
                                      Vec4f second = other.getCol(i);
                                      if (first != second) return false;
                                 } return true; }

  bool operator !=(Mat& other) { return !(*this == other); } // TODO: optimize this

  static const Mat XRotMat(float theta);
  static const Mat YRotMat(float theta);
  static const Mat ZRotMat(float theta);
  static const Mat TransMat(int x, int y, int z);
  static const Mat ScaleMat(float x, float y, float z);

};
