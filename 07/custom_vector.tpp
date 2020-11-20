template <typename T, class AllocT>
Vector<T, AllocT>::Vector(size_t size_) : data(new T[size_]), 
                                 size(size_),
                                 capacity(size_) {}

template <typename T, class AllocT>
Vector<T, AllocT>& Vector<T, AllocT>::operator= (const Vector &arg) {
  size = arg.Size();
  capacity = arg.Capacity();
  if (data != nullptr) {
    delete [] data;
  }
  data = new T [size];
  move(arg.begin(), arg.end(), begin());
  return *this;
}

template <typename T, class AllocT>
Vector<T, AllocT>::~Vector() {
  delete[] data;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::Reserve(size_t size_) {
  data = new T[size];
  size = size_;
  capacity = size_;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::Resize(size_t size_) {
  throw std::runtime_error("Resize Not Implemented")
}

template <typename T, class AllocT>
T& Vector<T, AllocT>::operator[](size_t index) {
  return data[index];
}

template <typename T, class AllocT>
size_t Vector<T, AllocT>::Size() const {
  return size;
}

template <typename T, class AllocT>
size_t Vector<T, AllocT>::Capacity() const {
  return capacity;
}

template <typename T, class AllocT>
T* Vector<T, AllocT>::begin() {
  return data;
}

template <typename T, class AllocT>
T* Vector<T, AllocT>::end() {
  return data + size;
}

template <typename T, class AllocT>
const T* const Vector<T, AllocT>::begin() const {
  return data;
}

template <typename T, class AllocT>
const T* const Vector<T, AllocT>::rend() const {
  return data + size;
}

template <typename T, class AllocT>
T* Vector<T, AllocT>::rbegin() {
  return data;
}

template <typename T, class AllocT>
T* Vector<T, AllocT>::rend() {
  return data + size;
}

template <typename T, class AllocT>
const T* const Vector<T, AllocT>::rbegin() const {
  return data;
}

template <typename T, class AllocT>
const T* const Vector<T, AllocT>::end() const {
  return data + size;
}

template <typename T, class AllocT>
void Vector<T, AllocT>::PushBack(const T &value) {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = new T[new_cap];
    move(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
  data[size++] = move(value);
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