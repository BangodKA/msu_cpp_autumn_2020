#pragma once

#include <algorithm>

template <typename T, class AllocT>
class Vector {
public:
  Vector() = default;
  explicit Vector(size_t size_);
  Vector& operator= (const Vector &arg);
  ~Vector();

  void Reserve(size_t size_);
  void Resize(size_t size_);

  T& operator[](size_t index);

  T* begin();
  T* end();

  const T* const begin() const;
  const T* const end() const;

  T* rbegin();
  T* rend();

  const T* const rbegin() const;
  const T* const rend() const;

  size_t Size() const;
  size_t Capacity() const;

  void PushBack(const T &value);
  void PopBack();

  bool Empty() const noexcept;
  void Clear() noexcept;

private:
  T* data = nullptr;
  size_t size = 0;
  size_t capacity = 0;
};

#include "custom_vector.tpp"