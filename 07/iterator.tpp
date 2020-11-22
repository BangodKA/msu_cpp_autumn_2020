template <class ValueType>
RACIterator<ValueType>::RACIterator(pointer &&ptr) : current_(std::move(ptr)) {}

template <class ValueType>
RACIterator<ValueType>& RACIterator<ValueType>::operator+=(difference_type n) {
  current_ += n;
  return *this;
}

template <class ValueType>
RACIterator<ValueType> RACIterator<ValueType>::operator+(difference_type n) {
  RACIterator<ValueType> temp(*this);
  return temp += n;
}

template <class ValueType>
RACIterator<ValueType> operator+(typename RACIterator<ValueType>::difference_type n,
                                 const RACIterator<ValueType>& a) {
  RACIterator<ValueType> temp = a;
  return temp += n;
}

template <class ValueType>
RACIterator<ValueType>& RACIterator<ValueType>::operator-=(difference_type n) {
  current_ -= n;
  return *this;
}

template <class ValueType>
RACIterator<ValueType> RACIterator<ValueType>::operator-(difference_type n) {
  RACIterator<ValueType> temp(*this);
  return temp -= n;
}

template <class ValueType>
RACIterator<ValueType> operator-(typename RACIterator<ValueType>::difference_type n,
                                        const RACIterator<ValueType>& a) {
  RACIterator<ValueType> temp = a;
  return temp -= n;
}

template <class ValueType>
RACIterator<ValueType>& RACIterator<ValueType>::operator++() {
  ++current_;
  return *this;
}

template <class ValueType>
RACIterator<ValueType>& RACIterator<ValueType>::operator--() {
  --current_;
  return *this;
}

template <class ValueType>
RACIterator<ValueType> RACIterator<ValueType>::operator++(int) {
  RACIterator<ValueType> temp(*this);
  ++current_;
  return temp;
}

template <class ValueType>
RACIterator<ValueType> RACIterator<ValueType>::operator--(int) {
  RACIterator<ValueType> temp(*this);
  --current_;
  return temp;
}

template <class ValueType>
typename RACIterator<ValueType>::difference_type 
  RACIterator<ValueType>::operator-(const RACIterator<ValueType>& rhs) {
  return this->current_ - rhs.current_;
}

template <class ValueType>
typename RACIterator<ValueType>::reference
  RACIterator<ValueType>::operator[] (difference_type n) {
  return current_[n];
}

template <class ValueType>
typename RACIterator<ValueType>::const_reference
  RACIterator<ValueType>::operator[] (difference_type n) const {
  return current_[n];
}

template <class ValueType>
bool RACIterator<ValueType>::operator==(const RACIterator& other) const {
    return current_ == other.current_;
}

template <class ValueType>
bool RACIterator<ValueType>::operator!=(const RACIterator& other) const {
    return !(*this == other);
}

template <class ValueType>
bool RACIterator<ValueType>::operator>(const RACIterator& other) const {
    return current_ - other.current_ > 0;
}

template <class ValueType>
bool RACIterator<ValueType>::operator>=(const RACIterator& other) const {
    return *this == other || *this > other;
}

template <class ValueType>
bool RACIterator<ValueType>::operator<(const RACIterator& other) const {
    return !(*this >= other);
}

template <class ValueType>
bool RACIterator<ValueType>::operator<=(const RACIterator& other) const {
    return !(*this > other);
}

template <class ValueType>
typename RACIterator<ValueType>::reference RACIterator<ValueType>::operator*() {
  return *current_;
}

template <class ValueType>
typename RACIterator<ValueType>::const_reference
  RACIterator<ValueType>::operator*() const {
  return *current_;
}