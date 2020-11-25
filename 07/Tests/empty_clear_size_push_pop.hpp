#pragma once

#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestEmptyClearSizePushPop() {
  { // EmptyClear
    Vector<int> my_numbers;
    assert(my_numbers.Empty() == true);

    my_numbers.PushBack(42);
    assert(my_numbers.Empty() == false);

    my_numbers.Clear();
    assert(my_numbers.Empty() == true);
  }

  { // Size
    Vector<int> nums = {1, 2, 3, 100};
    assert(nums.Size() == 4);

    Vector<char> empty_vec;
    assert(empty_vec.Size() == 0);
  }

  std::ostringstream my_vec_out;
  std::ostringstream std_vec_out;

  { // PushBack
    Vector<std::string> my_letters;
    std::vector<std::string> std_letters;
 
    std_letters.push_back("abc");
    std::string std_s = "def";
    std_letters.push_back(std::move(std_s));
 
    for (auto&& i : std_letters) 
      std_vec_out << std::quoted(i) << ' ';
    std_vec_out << std::quoted(std_s) << '\n';

    my_letters.PushBack("abc");
    std::string my_s = "def";
    my_letters.PushBack(std::move(my_s));
 
    for (auto&& i : my_letters) 
      my_vec_out << std::quoted(i) << ' ';
    my_vec_out << std::quoted(my_s) << '\n';

    assert(my_vec_out.str() == std_vec_out.str());
  }

  { // PopBack
    Vector<int> my_numbers = {4, 3, 5};
    std::vector<int> std_numbers = {4, 3, 5};
    
    my_numbers.PopBack();
    std_numbers.pop_back();

    assert(std_numbers == my_numbers);
  }
}