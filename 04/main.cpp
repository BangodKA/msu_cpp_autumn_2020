#include <iostream>
#include <string>
#include "bigint.hpp"

int main() {
  const BigInt temp("-12412");
  std::cout << BigInt("-923") + temp << std::endl;
  return 0;
}