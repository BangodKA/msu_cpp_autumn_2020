#pragma once

#include <cassert>
#include <sstream>
#include <vector>

#include <iostream>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestEmplaceBack() {
  Vector<int> my_test = {1, 2, 3};
  std::vector<int> std_test = {1, 2, 3};
  assert(std_test == my_test);
  my_test.EmplaceBack(10);
  std_test.emplace_back(10);
  assert(std_test == my_test);
  my_test.EmplaceBack(10);
  my_test.EmplaceBack(11);
  my_test.EmplaceBack(100);
  my_test.EmplaceBack(140);
  my_test.EmplaceBack(134);
  my_test.EmplaceBack(16857);
  my_test.EmplaceBack(13453);
  my_test.EmplaceBack(1534);
  my_test.EmplaceBack(4530);
  my_test.EmplaceBack(92349);
  std_test.emplace_back(10);
  std_test.emplace_back(11);
  std_test.emplace_back(100);
  std_test.emplace_back(140);
  std_test.emplace_back(134);
  std_test.emplace_back(16857);
  std_test.emplace_back(13453);
  std_test.emplace_back(1534);
  std_test.emplace_back(4530);
  std_test.emplace_back(92349);
  assert(std_test == my_test);
}