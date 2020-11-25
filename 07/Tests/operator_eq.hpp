#pragma once

#include <cassert>
#include <sstream>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestOperatorEq() {
  std::vector<int> std_nums1 {3, 1, 4, 6, 5, 9};
  std::vector<int> std_nums2;
  std::vector<int> std_nums3;

  Vector<int> my_nums1 {3, 1, 4, 6, 5, 9};
  Vector<int> my_nums2;
  Vector<int> my_nums3;

  // copy assignment copies data from nums1 to nums2
  std_nums2 = std_nums1;
  my_nums2 = my_nums1;
  assert(std_nums2 == my_nums2);

  // move assignment moves data from nums1 to nums3,
  // modifying both nums1 and nums3
  my_nums3 = std::move(my_nums1);
  std_nums3 = std::move(std_nums1);
  assert(std_nums3 == my_nums3);

  // copy assignment of an initializer_list copies data to nums3
  my_nums3 = {1, 2, 3};
  std_nums3 = {1, 2, 3};
  assert(std_nums3 == my_nums3);
}