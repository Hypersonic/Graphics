#include "Mat.h"

void Mat::expand(int morerows, int morecols) {
  realloc(_data, (morerows*morecols)*(_rows*_cols)*sizeof(int));
  if (morerows != 0) { // Don't redo all the things if we don't need to
    for (int i = _rows; i >= 0; i--) {
      for (int j = _cols; j >= 0; j--) {
        _data[j * (_rows+morerows) + i] = get(i,j);
      }
    }
  }
  // Increase the stored row and col count to match
  _rows += morerows;
  _cols += morecols;
}

Mat Mat::getRow(int row) const {
  Mat res_row = Mat(1, _cols);
  for (int i = 0; i < _cols; i++) {
    res_row.get(i) = get(row, i);
  }
  return res_row;
}

Mat Mat::getCol(int col) const {
  Mat res_col = Mat(_rows, 1);
  for (int i = 0; i < _rows; i++) {
    res_col.get(i) = get(i, col);
  }
  return res_col;
}

// prereqs: m1._rows == m2._rows && m1._cols == m2._cols
int Mat::dot(const Mat m1, const Mat m2) const {
  int resultant = 0;
  for (int i = 0; i < m1._cols; i++) {
    resultant += m1.get(i) * m2.get(i);
  }
  return resultant;
}

Mat Mat::multiply(const Mat m2) {
  Mat resultant = Mat(m2._rows, _cols); // Make the resultant the correct size

  // For each intersection
  for (int i = 0; i < m2._rows; i++) {
    for (int j = 0; j < _cols; j++) {
      resultant.get(i,j) = dot(m2.getRow(i), getCol(j));
    }
  }
  return resultant;
}
