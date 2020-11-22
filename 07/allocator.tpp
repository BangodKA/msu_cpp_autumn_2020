template<class T>
typename CAllocator<T>::pointer CAllocator<T>::allocate(size_type count) const {
  return new T [count];
}

template<class T>
void CAllocator<T>::deallocate(pointer p, size_type) const {
  delete [] p;
}

template< class T1, class T2 >
bool operator==(const CAllocator<T1>&, const CAllocator<T2>&) noexcept {
  return true;
}

template< class T1, class T2 >
bool operator!=(const CAllocator<T1>&, const CAllocator<T2>&) noexcept {
  return false;
}