#include <stdio.h>
#include <iostream>

#include "task.hpp"

void Allocator::makeAllocator (size_t maxSize) {
  if (beginning != nullptr) {
    delete [] beginning;
  }
  beginning = new char[maxSize];
  capacity = maxSize;
  offset = 0;
}

char* Allocator::alloc(size_t size) {
  if (size <= 0) {
    return nullptr;
  }
  
  char* res = beginning + offset;
  size_t new_offset = offset + size;
  if (new_offset > capacity) {
    return nullptr;
  }
  offset = new_offset;
  return res;
}

void Allocator::reset() {
  offset = 0;
}

Allocator::~Allocator() {
  delete [] beginning;
}