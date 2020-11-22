#pragma once

#include <iterator>
template<class T>
struct CAllocator {
  using value_type = T;
  using size_type = std::size_t;
  using pointer = T*;
  using difference_type = std::ptrdiff_t;
  using is_always_equal = std::true_type;

  pointer allocate(size_type count) const;

  void deallocate(pointer p, size_type) const;
};

template< class T1, class T2 >
bool operator==(const CAllocator<T1>&, const CAllocator<T2>& rhs) noexcept;

template< class T1, class T2 >
bool operator!=(const CAllocator<T1>& lhs, const CAllocator<T2>& rhs) noexcept;

#include "allocator.tpp"