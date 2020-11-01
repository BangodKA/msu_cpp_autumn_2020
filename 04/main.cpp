#include <iostream>
#include <string>
#include "bigint.hpp"

int main() {
  const BigInt   temp("119");
  // std::cout << temp << std::endl << BigInt("115") - temp << std::endl;
  // std::cout <<  BigInt("115") - BigInt("115") << std::endl;
  // std::cout <<  BigInt("115") - BigInt("234") << std::endl;
  // std::cout <<  BigInt("115") - BigInt("12115") << std::endl;
  // std::cout <<  BigInt("59") - BigInt("93484") << std::endl;
  // std::cout <<  BigInt("234") - BigInt("115") << std::endl;
  // std::cout <<  BigInt("12115") - BigInt("115") << std::endl;
  // std::cout <<  BigInt("93484") - BigInt("59") << std::endl;
  // std::cout << std::endl;
  // std::cout <<  BigInt("115") + BigInt("115") << std::endl;
  // std::cout <<  BigInt("115") + BigInt("234") << std::endl;
  // std::cout <<  BigInt("115") + BigInt("12115") << std::endl;
  // std::cout <<  BigInt("59") + BigInt("93484") << std::endl;
  // std::cout <<  BigInt("234") + BigInt("115") << std::endl;
  // std::cout <<  BigInt("12115") + BigInt("115") << std::endl;
  // std::cout <<  BigInt("93484") + BigInt("59") << std::endl;
  // std::cout << std::endl;
  // std::cout <<  -BigInt("115") - BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("115") - BigInt("-234") << std::endl;
  // std::cout <<  -BigInt("115") - BigInt("-12115") << std::endl;
  // std::cout <<  -BigInt("59") - BigInt("-93484") << std::endl;
  // std::cout <<  -BigInt("234") - BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("12115") - BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("93484") - BigInt("-59") << std::endl;
  // std::cout << std::endl;
  // std::cout <<  -BigInt("115") + BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("115") + BigInt("-234") << std::endl;
  // std::cout <<  -BigInt("115") + BigInt("-12115") << std::endl;
  // std::cout <<  -BigInt("59") + BigInt("-93484") << std::endl;
  // std::cout <<  -BigInt("234") + BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("12115") + BigInt("-115") << std::endl;
  // std::cout <<  -BigInt("93484") + BigInt("-59") << std::endl;


  // std::cout <<  BigInt("333333333333333333333333289") - BigInt("333333333333333333333333987") << std::endl;
  // std::cout <<  BigInt("333333333333333433333333289") - BigInt("333333333333373333333333987") << std::endl;
  // std::cout <<  BigInt("333333333333333433333333987") - BigInt("333333333333373333333333289") << std::endl;

  std::cout << BigInt("99") + BigInt("90") << std::endl;
  std::cout << BigInt("-99") + -BigInt("90") << std::endl;
  
  return 0;
}