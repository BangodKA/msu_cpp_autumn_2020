#pragma once

#include <cassert>
#include <sstream>
#include <string>
#include <vector>


#include "output.hpp"

void TestConstructors() {
  std::ostringstream my_vec_out;
  std::ostringstream std_vec_out;
  
  Vector<std::string> my_words1 {"the", "frogurt", "is", "also", "cursed"};
  std::vector<std::string> std_words1 {"the", "frogurt", "is", "also", "cursed"};
  output_res(my_vec_out, std_vec_out, my_words1, std_words1);
  assert(my_vec_out.str() == std_vec_out.str());

  // words2 == words1
  Vector<std::string> my_words2(my_words1.begin(), my_words1.end());
  std::vector<std::string> std_words2(std_words1.begin(), std_words1.end());
  output_res(my_vec_out, std_vec_out, my_words2, std_words2);
  assert(my_vec_out.str() == std_vec_out.str());

  // words3 == words1
  Vector<std::string> my_words3(my_words1);
  std::vector<std::string> std_words3(std_words1);
  output_res(my_vec_out, std_vec_out, my_words3, std_words3);
  assert(my_vec_out.str() == std_vec_out.str());

  // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
  Vector<std::string> my_words4(5, "Mo");
  std::vector<std::string> std_words4(5, "Mo");
  output_res(my_vec_out, std_vec_out, my_words4, std_words4);
  assert(my_vec_out.str() == std_vec_out.str());
}