#include <cassert>
#include <iostream>
#include <string>

#include "exceptions.hpp"
#include "format.hpp"

int main() {
  std::string test = "first:{1} second::{2};first – {1}; third {3}. last-{1}!";
  int test_number = 123;
  assert("first:123 second::gdgd;first – 123; third 74357. last-123!" == format(test, test_number, "gdgd", 74357));

  try {
    format(test, 123, 8);
  } catch (const NotEnoughArgsError &e) {
    assert(e.what() == std::string("./format.tpp::11::Error: Not enough arguments in format"));
  }

  try {
    format(std::string("{"), 123);
  } catch (const BraceUsageError &e) {
    assert(e.what() == std::string("./format.tpp::60::Error: '{' usage is inappropriate"));
  }

  try {
    format(std::string("{}"), 123);
  } catch (const BraceUsageError &e) {
    assert(e.what() == std::string("./format.tpp::48::Error: no argument inside '{}'"));
  }

  try {
    format(std::string("}"), 123);
  } catch (const BraceUsageError &e) {
    assert(e.what() == std::string("./format.tpp::54::Error: '}' usage is inappropriate"));
  }

  try {
    format(std::string("{r}}"), 123);
  } catch (const ArgumentError &e) {
    assert(e.what() == std::string("./format.tpp::51::Error: argument must be a number"));
  }

  std::cout << "Tests passed!" << std::endl;
  return 0;
}