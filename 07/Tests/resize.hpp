#pragma once

#include <cassert>
#include <sstream>
#include <string>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestResize() {
  std::ostringstream my_vec_out;
  std::ostringstream std_vec_out;
  
  std::vector<int> std_nums = {1, 2, 3};
  std_vec_out << "The vector holds: ";
  for(auto& el: std_nums) std_vec_out << el << ' ';
  std_vec_out << '\n';
  std_nums.resize(5);
  std_vec_out << "After resize up to 5: ";
  for(auto& el: std_nums) std_vec_out << el << ' ';
  std_vec_out << '\n';
  std_nums.resize(2);
  std_vec_out << "After resize down to 2: ";
  for(auto& el: std_nums) std_vec_out << el << ' ';
  std_vec_out << '\n';

  Vector<int> my_nums = {1, 2, 3};
  my_vec_out << "The vector holds: ";
  for(auto& el: my_nums) my_vec_out << el << ' ';
  my_vec_out << '\n';
  my_nums.Resize(5);
  my_vec_out << "After resize up to 5: ";
  for(auto& el: my_nums) my_vec_out << el << ' ';
  my_vec_out << '\n';
  my_nums.Resize(2);
  my_vec_out << "After resize down to 2: ";
  for(auto& el: my_nums) my_vec_out << el << ' ';
  my_vec_out << '\n';
  
  assert(my_vec_out.str() == std_vec_out.str());
  assert(std_nums == my_nums);
}