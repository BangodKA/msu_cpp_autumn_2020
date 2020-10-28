#pragma once

#include <iostream>

class Row {
 public:
  Row(size_t cols_ = 0);
  ~Row();
  int& operator[](size_t i) const;
  Row& operator*=(int num);
  Row operator+(const Row& rhs) const;
  bool operator==(const Row& rhs) const;
  bool operator!=(const Row& rhs) const;
 private:
  friend std::ostream& operator<<(std::ostream& out, const Row& data);
  const size_t cols;
  int* row;
};

class Matrix {
 public:
  Matrix(size_t cols_, size_t rows_);
  ~Matrix();
  size_t GetCols() const;
  size_t GetRows() const;
  Row& operator[](size_t i) const;
  Matrix& operator*=(int num);
  Matrix operator+(const Matrix& rhs) const;
  bool operator==(const Matrix& rhs) const;
  bool operator!=(const Matrix& rhs) const;
 private:
  friend std::ostream& operator<<(std::ostream& out, const Matrix& data);
  const size_t cols;
  const size_t rows;
  Row** matrix;
};