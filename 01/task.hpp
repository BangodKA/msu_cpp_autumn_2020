#pragma once

#include <stdio.h>

class Allocator {
 public:
  void makeAllocator(size_t maxSize);
  char* alloc(size_t size);
  void reset();
  ~Allocator();
 private:
  char *beginning = nullptr;
  size_t capacity = 0;
  int offset = 0;
};