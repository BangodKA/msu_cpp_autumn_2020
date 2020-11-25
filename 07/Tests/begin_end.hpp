#pragma once

#include <numeric>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestBeginEnd() {
  std::ostringstream my_vec_out;
  std::ostringstream std_vec_out;
  
  Vector<int> my_nums {1, 2, 4, 8, 16};
  Vector<std::string> my_fruits {"orange", "apple", "raspberry"};
  Vector<char> my_empty;

  std::vector<int> std_nums {1, 2, 4, 8, 16};
  std::vector<std::string> std_fruits {"orange", "apple", "raspberry"};
  std::vector<char> std_empty;

  std::for_each(my_nums.begin(), my_nums.end(), [&my_vec_out](const int n) {my_vec_out << n << ' '; });
  std::for_each(std_nums.begin(), std_nums.end(), [&std_vec_out](const int n) {std_vec_out << n << ' ';});
  assert(my_vec_out.str() == std_vec_out.str());
 
  // Print vector.
  std::for_each(my_nums.rbegin(), my_nums.rend(), [&my_vec_out](const int n) {my_vec_out << n << ' '; });
  std::for_each(std_nums.rbegin(), std_nums.rend(), [&std_vec_out](const int n) {std_vec_out << n << ' ';});
  assert(my_vec_out.str() == std_vec_out.str());

  // Sums all integers in the vector nums (if any), printing only the result.
  assert(std::accumulate(my_nums.begin(), my_nums.end(), 0) == std::accumulate(std_nums.begin(), std_nums.end(), 0));

  assert(std::accumulate(my_nums.rbegin(), my_nums.rend(), 0) == std::accumulate(std_nums.rbegin(), std_nums.rend(), 0));

  // Prints the first fruit in the vector fruits, checking if there is any.
  if (!std_fruits.empty())
    std_vec_out << *std_fruits.begin() << '\n';
  if (!my_fruits.Empty())
    my_vec_out << *my_fruits.begin() << '\n';
  assert(my_vec_out.str() == std_vec_out.str());

  if (!std_fruits.empty())
    std_vec_out << *std_fruits.rbegin() << '\n';
  if (!my_fruits.Empty())
    my_vec_out << *my_fruits.rbegin() << '\n';
  assert(my_vec_out.str() == std_vec_out.str());

  my_vec_out << (my_empty.begin() == my_empty.end());
  std_vec_out << (std_empty.begin() == std_empty.end());
  assert(my_vec_out.str() == std_vec_out.str());

  my_vec_out << (my_empty.rbegin() == my_empty.rend());
  std_vec_out << (std_empty.rbegin() == std_empty.rend());
  assert(my_vec_out.str() == std_vec_out.str());
}