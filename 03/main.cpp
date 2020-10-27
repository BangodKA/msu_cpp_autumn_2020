#include <cassert>
#include <iostream>
#include <sstream>


#include "matrix.hpp"

int main() {
  const size_t rows = 5;
  const size_t cols = 3;

  Matrix first(cols, rows);

  assert(first.GetRows() == 5);
  assert(first.GetCols() == 3);

  double x = first[4][1];
  assert(x == 0);

  first[1][2] = 5;
  double y = first[1][2];
  assert(y == 5);

  std::stringstream errc;
  Matrix test(cols + 1, rows);
  try {
    test + first;
  } catch (const std::out_of_range  & e) {
    errc << e.what() << std::endl;
  }
  try {
    test[10][0];
  } catch (const std::out_of_range  & e) {
    errc << e.what() << std::endl;
  }

  try {
    test[0][10];
  } catch (const std::out_of_range  & e) {
    errc << e.what() << std::endl;
  }

  std::stringstream real_errc;
  real_errc << "Wrong dims" << std::endl <<
               "Too big row" << std::endl <<
               "Too big col" << std::endl;
  assert(errc.str() == real_errc.str());
  
  first *= 3;
  double z = first[1][2];
  double new_x = first[4][1];
  assert(x == 0);
  assert(y == 5);
  assert(new_x == 0);
  assert(z == 15);

  Matrix second(cols, rows);
  assert(first != second);

  Matrix third = second + first;
  assert(third == first);

  std::stringstream res;
  res << third << std::endl;
  std::stringstream real_res;
  real_res << "   0   0   0" << std::endl <<
              "   0   0  15" << std::endl <<
              "   0   0   0" << std::endl <<
              "   0   0   0" << std::endl <<
              "   0   0   0" << std::endl;
  assert(res.str() == real_res.str());

  std::cout << "Tests passed! Program accepted?" << std::endl;

  return 0;
}