#include <cassert>
#include <iostream>
#include <future>
#include <vector>

#include "pool.hpp"

struct A {};

void foo(const A&) {}

int second_foo(int i, int j) {
  return i * i - j * 2;
}

int main() {
  ThreadPool first_pool(8);

  auto task1 = first_pool.exec(foo, A());
  task1.get();

  auto task2 = first_pool.exec([]() { return 1; });
  assert(task2.get() == 1);

  ThreadPool second_pool(4);

  for (int i = 1; i <= 4; ++i) {
    auto task = second_pool.exec(second_foo, i, 3);
    assert(task.get() == i * i - 6);
  }

  std::cout << "Tests passed!" << std::endl;
  return 0;
}