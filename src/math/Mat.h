#pragma once

#include <stdlib.h>

#include "debug.h"

class Mat {
protected:
  int _rows, _cols;
  int* _data;
public:
  Mat(int rows, int cols) : _rows(rows), _cols(cols), _data(reinterpret_cast<int*>(malloc(rows*cols*sizeof(rows)))) {}
  
  ~Mat() { free(_data); }

  int  get(int row, int col=0) const { return _data[col * _rows + row]; }
  int& get(int row, int col=0)       { return _data[col * _rows + row]; }

  Mat getRow(int row) const; // Return the requested row
  Mat getCol(int col) const; // Return the requested col

  void expand(int morerows, int morecols); // Expand the matrix, placing elements to match the existing one.

  int dot(const Mat m1, const Mat m2) const; // Calculate the dot product of two collum matrices of equal length
  
  Mat multiply(const Mat m2); // this * m2
};
