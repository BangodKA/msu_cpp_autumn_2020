#pragma once

#include <cassert>
#include <sstream>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestOperatorAcc() {
  Vector<int> my_numbers {2, 4, 6, 8};
  std::vector<int> std_numbers {2, 4, 6, 8};
 
  assert(my_numbers[1] == std_numbers[1]);
 
  my_numbers[0] = 5;
  std_numbers[0] = 5;

  assert(std_numbers == my_numbers);
}