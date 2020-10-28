#include <iomanip>
#include <iostream>

#include "matrix.hpp"

Row::Row(size_t cols_) : cols(cols_) {
  row = new int[cols];
  for (size_t i = 0; i < cols; ++i) {
    row[i] = 0;
  }
}

Row::~Row() {
  delete [] row;
}

int& Row::operator[](size_t i) const {
  if (i >= cols) {
    throw std::out_of_range("Too big col");
  }
  return row[i];
}

Row& Row::operator*=(int num) {
  for (size_t i = 0; i < cols; ++i) {
    row[i] *= num;
  }
  return *this;
}

Row Row::operator+(const Row& rhs) const {
  Row res(cols);
  for (size_t i = 0; i < cols; ++i) {
    res[i] = row[i] + rhs[i];
  }
  return res;
}

bool Row::operator==(const Row& rhs) const {
  for (size_t i = 0; i < cols; ++i) {
    if (row[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

bool Row::operator!=(const Row& rhs) const {
  for (size_t i = 0; i < cols; ++i) {
    if (row[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& out, const Row& data) {
  for (size_t i = 0; i < data.cols; ++i) {
    out << std::setw(4) << data[i];
  }
  return out;
}


Matrix::Matrix(size_t cols_, size_t rows_) : cols(cols_), rows(rows_) {
  matrix = new Row* [rows];
  for (size_t i = 0; i < rows; ++i) {
    matrix[i] = new Row(cols);
  }
}

Matrix::~Matrix() {
  for (size_t i = 0; i < rows; ++i) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

size_t Matrix::GetCols() const {
  return cols;
}

size_t Matrix::GetRows() const {
  return rows;
}

Row& Matrix::operator[](size_t i) const {
  if (i >= rows) {
    throw std::out_of_range("Too big row");
  }
  return *matrix[i];
}

Matrix& Matrix::operator*=(int num) {
  for (size_t i = 0; i < rows; ++i) {
    *matrix[i] *= num;
  }
  return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
  if (rhs.rows != rows || rhs.cols != cols) {
    throw std::out_of_range("Wrong dims");
  }

  Matrix res(cols, rows);
  for (size_t i = 0; i < rows; ++i) {
    new (&res[i]) Row (*matrix[i] + rhs[i]);
  }
  return res;
}

bool Matrix::operator==(const Matrix& rhs) const {
  for (size_t i = 0; i < rows; ++i) {
    if (*matrix[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

bool Matrix::operator!=(const Matrix& rhs) const {
  for (size_t i = 0; i < rows; ++i) {
    if (*matrix[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& out, const Matrix& data) {
  for (size_t i = 0; i < data.GetRows(); ++i) {
    out << data[i];
    if (i != data.GetRows() - 1) {
      out << std::endl;
    }
  }
  return out;
}