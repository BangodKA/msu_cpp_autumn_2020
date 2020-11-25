#pragma once

#include <cassert>
#include <sstream>
#include <string>
#include <vector>

#include "../custom_vector.hpp"
#include "operators.hpp"

void TestConstructors() {  
  Vector<std::string> my_words1 {"the", "frogurt", "is", "also", "cursed"};
  std::vector<std::string> std_words1 {"the", "frogurt", "is", "also", "cursed"};
  assert(std_words1 == my_words1);

  // words2 == words1
  Vector<std::string> my_words2(my_words1.begin(), my_words1.end());
  std::vector<std::string> std_words2(std_words1.begin(), std_words1.end());
  assert(std_words2 == my_words2);

  // words3 == words1
  Vector<std::string> my_words3(my_words1);
  std::vector<std::string> std_words3(std_words1);
  assert(std_words3 == my_words3);

  // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
  Vector<std::string> my_words4(5, "Mo");
  std::vector<std::string> std_words4(5, "Mo");
  assert(std_words4 == my_words4);
}