#pragma once

#include <iterator>

template <class ValueType>
class RACIterator {
 public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = ValueType;
  using pointer = ValueType*;
  using reference = ValueType&;
  using const_reference = const ValueType&;
  
  RACIterator(pointer &&ptr = nullptr);
  RACIterator(const RACIterator<ValueType>&) = default;

  RACIterator<ValueType>& operator+=(difference_type n);

  RACIterator<ValueType> operator+(difference_type n);

  friend RACIterator<ValueType> operator+(difference_type n,
                                          const RACIterator<ValueType>& a);

  RACIterator<ValueType>& operator-=(difference_type n);

  RACIterator<ValueType> operator-(difference_type n);

  friend RACIterator<ValueType> operator-(difference_type n,
                                          const RACIterator<ValueType>& a);

  RACIterator<ValueType>& operator++();
  RACIterator<ValueType>& operator--();
  RACIterator<ValueType> operator++(int);
  RACIterator<ValueType> operator--(int);

  difference_type operator-(const RACIterator<ValueType>& rhs);

  reference operator[] (difference_type n);
  const_reference operator[] (difference_type n) const;


  bool operator==(const RACIterator& other) const;

  bool operator!=(const RACIterator& other) const;

  bool operator>(const RACIterator& other) const;

  bool operator>=(const RACIterator& other) const;

  bool operator<(const RACIterator& other) const;

  bool operator<=(const RACIterator& other) const;

  reference operator*();
  const_reference operator*() const;

 private:
   pointer current_;
};

#include "iterator.tpp"