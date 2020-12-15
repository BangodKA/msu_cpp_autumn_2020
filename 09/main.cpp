#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "sort.hpp"

void ReadFile (std::vector<uint64_t>& nums, std::string filename) {
  std::ifstream file(filename);
  while (file.peek() != EOF) {
    uint64_t cur_n;
    file >> cur_n;
    nums.push_back(cur_n);
  }
}

int main() {
  // all files were generated using python
  { // empty
    std::vector<uint64_t> starting_perm;
    ReadFile(starting_perm, "Tests/test_1/test_1.txt");
    SortFile("Tests/test_1/test_1.txt");
    std::vector<uint64_t> res;
    ReadFile(res, "Tests/test_1/test_1_sorted.txt");
    std::sort(starting_perm.begin(), starting_perm.end());
    assert(res == starting_perm);
  }
  // next files have different amount of numbers
  { // 100 000
    std::vector<uint64_t> starting_perm;
    ReadFile(starting_perm, "Tests/test_2/test_2.txt");
    SortFile("Tests/test_2/test_2.txt");
    std::vector<uint64_t> res;
    ReadFile(res, "Tests/test_2/test_2_sorted.txt");
    std::sort(starting_perm.begin(), starting_perm.end());
    assert(res == starting_perm);
  }
  { // 20 000 000
    std::vector<uint64_t> starting_perm;
    ReadFile(starting_perm, "Tests/test_3/test_3.txt");
    SortFile("Tests/test_3/test_3.txt");
    std::vector<uint64_t> res;
    ReadFile(res, "Tests/test_3/test_3_sorted.txt");
    std::sort(starting_perm.begin(), starting_perm.end());
    assert(res == starting_perm);
  }
  std::cout << "Tests passed!" << std::endl;
  return 0;
}