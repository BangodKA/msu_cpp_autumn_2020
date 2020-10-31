#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

#include "bigint.hpp"

BigInt::BigInt(const std::string &data_) : capacity(data_.size()) {
  if (data_.size() == 0) {
    throw std::runtime_error("Error: not a number!");
  }

  int offset = !std::isdigit(data_[0]);
  size = data_.size() - offset;
  
  if (size == 0) {
    throw std::runtime_error("Error: not a number!");
  }

  if (data_[0] == '+') {
    sign = 1;
  } else if (data_[0] == '-') {
    sign = -1;
  } else if (!std::isdigit(data_[0])) {
    throw std::runtime_error("Error: not a number!");
  }

  data = new char [size];

  for (size_t i = offset; i < size; ++i) {

    if (!std::isdigit(data_[i])) {
        delete [] data;
        throw std::runtime_error("Error: not a number!");
    }

    data[size - 1 - i + offset] = data_[i];
  }
}

BigInt::BigInt(const BigInt &other_bigint) : sign(other_bigint.sign), 
                                             size(other_bigint.size), 
                                             capacity(other_bigint.capacity) {
  data = new char [size];

  for (size_t i = 0; i < size; ++i) {
    data[size - 1 - i] = other_bigint.data[i];
  }
}

BigInt::BigInt(BigInt &&other_bigint) : data(other_bigint.data),
                                        sign(other_bigint.sign), 
                                        size(other_bigint.size), 
                                        capacity(other_bigint.capacity) {
  other_bigint.data = nullptr;
  other_bigint.size = other_bigint.capacity = 0;
}

BigInt& BigInt::operator=(const BigInt &other_bigint) {
  if (data == other_bigint.data) {
    return *this;
  }

  if (data != nullptr) {
    delete [] data;
  }
  
  sign = other_bigint.sign;
  size = other_bigint.size;
  capacity = other_bigint.capacity;

  data = new char [size];

  for (size_t i = 0; i < size; ++i) {
    data[size - 1 - i] = other_bigint.data[i];
  }

  return *this;
}

BigInt& BigInt::operator=(BigInt &&other_bigint) {
  if (data == other_bigint.data) {
    return *this;
  }

  if (data != nullptr) {
    delete [] data;
  }

  data = other_bigint.data;
  sign = other_bigint.sign;
  size = other_bigint.size;
  capacity = other_bigint.capacity;

  other_bigint.data = nullptr;
  other_bigint.size = other_bigint.capacity = 0;

  return *this;
}

BigInt::~BigInt() {
  if (data != nullptr) {
    delete [] data;
  }
  size = capacity = 0;
}


BigInt BigInt::operator+(const BigInt &other_bigint) {
  size_t poss_size = std::max(size, other_bigint.size);
  char *res = new char [poss_size];

  for (size_t i = poss_size; i < poss_size; ++i) {
    
  }
}

BigInt BigInt::operator-(const BigInt &other_bigint) {

}

BigInt BigInt::operator*(const BigInt &other_bigint) {

}

BigInt BigInt::operator-() {

}


bool BigInt::operator<(const BigInt &other_bigint) {

}

bool BigInt::operator<=(const BigInt &other_bigint) {

}

bool BigInt::operator>(const BigInt &other_bigint) {

}

bool BigInt::operator>=(const BigInt &other_bigint) {

}

bool BigInt::operator==(const BigInt &other_bigint) {

}

bool BigInt::operator!=(const BigInt &other_bigint) {

}

std::ostream &operator<<(std::ostream &out, const BigInt &bigint) {

}
