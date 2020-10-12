#include <cassert>

#include "task.hpp"

using namespace std;

int main() {
  Allocator one_allocator;
  one_allocator.makeAllocator(10);

  char* first_allocated = one_allocator.alloc(11);
  assert(first_allocated == nullptr);
  
  first_allocated = one_allocator.alloc(4);

  assert(first_allocated != nullptr);

  assert(one_allocator.alloc(8) == nullptr);

  char* second_allocated = one_allocator.alloc(6);
  assert(second_allocated - first_allocated == 4);

  assert(one_allocator.alloc(1) == nullptr);

  one_allocator.reset();

  assert(one_allocator.alloc(10) != nullptr);

  assert(one_allocator.alloc(1) == nullptr);

  one_allocator.makeAllocator(20);

  first_allocated = one_allocator.alloc(11);

  assert(first_allocated != nullptr);

  second_allocated = one_allocator.alloc(4);
  assert(second_allocated - first_allocated == 11);

  char* third_allocated = one_allocator.alloc(3);
  assert(third_allocated - first_allocated == 15);
  assert(second_allocated - third_allocated == -4);

  assert(one_allocator.alloc(3) == nullptr);

  return 0;
}