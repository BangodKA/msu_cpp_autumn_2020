#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "custom_vector.hpp"

#include "Tests/operators.hpp"
#include "Tests/constructors.hpp"
#include "Tests/operator_eq.hpp"
#include "Tests/operator_acc.hpp"
#include "Tests/begin_end.hpp"
#include "Tests/empty_clear_size_push_pop.hpp"
#include "Tests/resize.hpp"
#include "Tests/emplace.hpp"


int main() {
  TestConstructors();
  TestOperatorEq();
  TestOperatorAcc();
  TestBeginEnd();
  TestEmptyClearSizePushPop();
  TestResize();
  TestEmplaceBack();

  std::cout << "Tests passed!" << std::endl;
  return 0;
}