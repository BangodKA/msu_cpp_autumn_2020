#include <algorithm>

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(const AllocT& alloc) noexcept {
  size = capacity = 0;
  data = alloc.allocate(0);
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(size_type size_, const_reference value,
                          const AllocT& alloc) : size(size_),
                                                 capacity(size_) {
  data = alloc.allocate(capacity);
  std::fill(begin(), end(), value);
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(Vector<T, AllocT>::size_type size_,
                          const AllocT& alloc) : size(size_),
                                                 capacity(size_) {
  data = alloc.allocate(capacity);
}

template <typename T, class AllocT>
template< class InputIt >
Vector<T, AllocT>::Vector(InputIt first, InputIt last, const AllocT& alloc) {
  for (InputIt i = first; i != last; ++i) {
    size++;
  }
  capacity = size;
  data = alloc.allocate(capacity);
  std::copy(first, last, begin());
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(const Vector& other) : size(other.size),
                                                 capacity(other.capacity) {
  data = AllocT().allocate(capacity);
  std::copy(other.begin(), other.end(), begin());
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(const Vector& other,
                          const AllocT& alloc) : size(other.size),
                                                 capacity(other.capacity) {
  data = alloc.allocate(capacity);
  std::copy(other.begin(), other.end(), begin());                                                 
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(Vector&& other) noexcept : size(other.size),
                                                     capacity(other.capacity) {
  other.size = other.capacity = 0;                                                    
  data = AllocT().allocate(capacity);
  std::move(other.begin(), other.end(), begin());
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(Vector&& other,
                          const AllocT& alloc) : size(other.size),
                                                 capacity(other.capacity) {
  other.size = other.capacity = 0;                                                    
  data = alloc.allocate(capacity);
  std::move(other.begin(), other.end(), begin());
}

template <typename T, class AllocT>
Vector<T, AllocT>::Vector(std::initializer_list<T> init, 
                          const AllocT& alloc) : size(init.size()),
                                                 capacity(init.size()) {
  data = alloc.allocate(capacity);
  std::copy(init.begin(), init.end(), begin());
}

template <typename T, class AllocT>
Vector<T, AllocT>::~Vector() {
  if (data != nullptr) {
    AllocT().deallocate(data, capacity);
    data = nullptr;
  }
  size = capacity = 0;
}

template <typename T, class AllocT>
Vector<T, AllocT>& Vector<T, AllocT>::operator=(const Vector &arg) {
  this->~Vector();
  size = arg.Size();
  capacity = arg.Capacity();
  data = AllocT().allocate(capacity);
  std::copy(arg.begin(), arg.end(), begin());
  return *this;
}

template <typename T, class AllocT>
Vector<T, AllocT>& Vector<T, AllocT>::operator=(Vector &&arg) noexcept {
  this->~Vector();
  size = arg.Size();
  capacity = arg.Capacity();
  data = AllocT().allocate(capacity);
  std::move(arg.begin(), arg.end(), begin());
  arg.size = arg.capacity = 0;
  return *this;
}

template <typename T, class AllocT>
Vector<T, AllocT>& Vector<T, AllocT>::operator=(std::initializer_list<T> ilist) {
  size = ilist.size();
  std::copy(ilist.begin(), ilist.end(), begin());
  return *this;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::Reserve(Vector<T, AllocT>::size_type size_) {
  if (capacity < size_) {
    this->~Vector();
    data = AllocT().allocate(size);
    capacity = size_;
  }
  size = size_;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::Resize(size_type size_, const_reference value) {
  if (size_ <= size) {
    size = size_;
  } else {
    size_type old_size = size;
    if (size_ > capacity) {
      size_type old_capacity = capacity;
      while (capacity < size_) {
        capacity *= 2;
      }
      Vector<T, AllocT> new_vector(capacity);
      std::move(begin(), end(), new_vector.begin());
      this->~Vector();
      *this = std::move(new_vector);
    }
    size = size_;
    std::fill(begin() + old_size, begin() + size, value);
  }
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::reference Vector<T, AllocT>::operator[](size_type index) {
  return iterator(&(data[0]))[index];
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::const_reference Vector<T, AllocT>::operator[](size_type index) const {
  return const_iterator(&(data[0]))[index];
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::size_type Vector<T, AllocT>::Size() const {
  return size;
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::size_type Vector<T, AllocT>::Capacity() const {
  return capacity;
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::iterator Vector<T, AllocT>::begin() {
  return iterator(&data[0]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::iterator Vector<T, AllocT>::end() {
  return iterator(&data[size]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::const_iterator Vector<T, AllocT>::begin() const {
  return const_iterator(&data[0]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::const_iterator Vector<T, AllocT>::end() const {
  return const_iterator(&data[size]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::reverse_iterator Vector<T, AllocT>::rbegin() {
  return reverse_iterator(&data[size]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::reverse_iterator Vector<T, AllocT>::rend() {
  return reverse_iterator(&data[0]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::const_reverse_iterator Vector<T, AllocT>::rbegin() const {
  return const_reverse_iterator(&data[size]);
}

template <typename T, class AllocT>
typename Vector<T, AllocT>::const_reverse_iterator Vector<T, AllocT>::rend() const {
  return const_reverse_iterator(&data[0]);
}

template <typename T, class AllocT>
void Vector<T, AllocT>::PushBack(const T &value) {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = AllocT().allocate(new_cap);
    std::move(begin(), end(), new_data);
    AllocT().deallocate(data, capacity);
    data = new_data;
    capacity = new_cap;
  }
  data[size++] = value;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::PushBack(T &&value) {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = AllocT().allocate(new_cap);
    std::move(begin(), end(), new_data);
    AllocT().deallocate(data, capacity);
    data = new_data;
    capacity = new_cap;
  }
  data[size++] = std::move(value);
}

template <typename T, class AllocT>
template <class... Args>
typename Vector<T, AllocT>::reference Vector<T, AllocT>::EmplaceBack(Args&&... args) {
  if (size == capacity) {
    capacity *= 2;
    auto new_data = AllocT().allocate(capacity);
    if (data != nullptr) {
      delete [] data;
    }
    data = new_data;
  }
  auto elem = new (data + size) T(std::move(args)...);
  ++size;
  return *elem;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::PopBack() {
  if (size != 0) {
    size--;
  }
}

template <typename T, class AllocT>
bool Vector<T, AllocT>::Empty() const noexcept {
  if (size == 0) {
    return true;
  }
  return false;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::Clear() noexcept {
  size = 0;
}

template< class T, class Alloc >
constexpr bool operator==(const Vector<T,Alloc>& lhs,
                          const Vector<T,Alloc>& rhs ) {
  if (lhs.size != rhs.size) {
    return false;
  }
  for (std::size_t i = 0; i < lhs.size; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}