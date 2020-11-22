#pragma once

#include <cassert>
#include <sstream>
#include <vector>

#include "output.hpp"

void TestOperatorAcc() {
  std::ostringstream my_vec_out;
  std::ostringstream std_vec_out;
  
  Vector<int> my_numbers {2, 4, 6, 8};
  std::vector<int> std_numbers {2, 4, 6, 8};
 
  assert(my_numbers[1] == std_numbers[1]);
 
  my_numbers[0] = 5;
  std_numbers[0] = 5;

  output_res(my_vec_out, std_vec_out, my_numbers, std_numbers);
  assert(my_vec_out.str() == std_vec_out.str());
}