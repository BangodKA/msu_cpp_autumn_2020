#pragma once

template<class T>
struct allocator {
  T value_type;
  std::size_t size_type;
  std::ptrdiff_t difference_type;
  std::true_type is_always_equal;

  allocator() noexcept;
  allocator(const allocator &other) noexcept;

  template<class U>
  allocator(const allocator<U> &other) noexcept;

  ~allocator();

  T* allocate(std::size_t n);

  void deallocate(T *p, std::size_t n);
};

template< class T1, class T2 >
bool operator==(const allocator<T1>& lhs, const allocator<T2>& rhs) noexcept;

template< class T1, class T2 >
bool operator!=(const allocator<T1>& lhs, const allocator<T2>& rhs) noexcept;