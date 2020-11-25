#pragma once

#include <algorithm>
#include <initializer_list>

#include "allocator.hpp"
#include "iterator.hpp"

template <typename T, class AllocT = CAllocator<T> >
class Vector {
  using allocator_type = AllocT;
  using iterator = RACIterator<T>;
  using const_iterator = RACIterator<const T>;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  using value_type = T;

  using reference = value_type&;
  using const_reference = const value_type&;

  using pointer = value_type*;
  using const_pointer = const value_type*;

  using size_type = std::size_t;

 public:
  Vector() noexcept(noexcept(AllocT())) = default;
  explicit Vector(const AllocT& alloc) noexcept;
  Vector(size_type size_, const_reference value,
         const AllocT& alloc = AllocT());
  explicit Vector(size_type size_, const AllocT& alloc = AllocT());

  template< class InputIt >
  Vector(InputIt first, InputIt last, const AllocT& alloc = AllocT());

  Vector(const Vector& other);
  Vector(const Vector& other, const AllocT& alloc);
  Vector(Vector&& other) noexcept;
  Vector(Vector&& other, const AllocT& alloc);
  Vector(std::initializer_list<T> init, 
         const AllocT& alloc = AllocT());
  ~Vector();

  Vector& operator= (const Vector &arg);
  Vector& operator=(Vector&& arg) noexcept;
  Vector& operator=(std::initializer_list<T> ilist);

  void Reserve(size_type size_);
  void Resize(size_type size_, const_reference value = *(new T()));

  reference operator[](size_type index);
  const_reference operator[](size_type index) const;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;

  size_type Size() const;
  size_type Capacity() const;

  void PushBack(const T &value);
  void PushBack(T&& value);
  
  template <class... Args>
  reference EmplaceBack( Args&&... args );

  void PopBack();

  bool Empty() const noexcept;
  void Clear() noexcept;

 private:
  void Realloc();

  pointer data = nullptr;
  size_type size = 0;
  size_type capacity = 0;
};

template< class T, class Alloc >
constexpr bool operator==( const Vector<T,Alloc>& lhs,
                           const Vector<T,Alloc>& rhs );

#include "custom_vector.tpp"