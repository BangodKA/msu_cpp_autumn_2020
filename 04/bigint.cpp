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

  if (data_[0] == '-') {
    sign = -1;
  } else if (!std::isdigit(data_[0]) && data_[0] != '+') {
    throw std::runtime_error("Error: not a number!");
  }

  data = new char [size];

  for (size_t i = offset; i < data_.size(); ++i) {
    if (!std::isdigit(data_[i])) {
        delete [] data;
        throw std::runtime_error("Error: not a number!");
    }

    data[i - offset] = data_[i];
  }
}

BigInt::BigInt(const BigInt &other_bigint) : sign(other_bigint.sign), 
                                             size(other_bigint.size), 
                                             capacity(other_bigint.capacity) {
  data = new char [size];

  for (size_t i = 0; i < size; ++i) {
    data[i] = other_bigint.data[i];
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
    data[i] = other_bigint.data[i];
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


BigInt BigInt::operator+(const BigInt &other_bigint) const {
  if (sign != other_bigint.sign) {
    return *this - (-other_bigint);
  }

  size_t res_size = std::max(size, other_bigint.size);
  char *res = new char [res_size + 2];
  res[0] = (sign == 1) ? '+' : '-';
  int dec = 0;

  for (size_t i = 0; i < res_size; ++i) {
    int first_dig = (i < size) ? data[size - i - 1] - '0' : 0;
    int second_dig = (i < other_bigint.size) ? 
                     other_bigint.data[other_bigint.size - i - 1] - '0' : 0;
    
    int next_dig = first_dig + second_dig + dec;  
    res[i + 1] = '0' + next_dig % 10;

    dec = next_dig / 10;
  }

  res[res_size + 1] = (dec == 1) ? '1' : '\0';
  
  return BigInt(res);
}

BigInt BigInt::operator-(const BigInt &other_bigint) const {

}

BigInt BigInt::operator*(const BigInt &other_bigint) const {

}

BigInt BigInt::operator-() const {
  BigInt res(*this);
  res.sign *= -1;
  return res;
}


bool BigInt::operator<(const BigInt &other_bigint) const {

}

bool BigInt::operator<=(const BigInt &other_bigint) const {

}

bool BigInt::operator>(const BigInt &other_bigint) const {

}

bool BigInt::operator>=(const BigInt &other_bigint) const {

}

bool BigInt::operator==(const BigInt &other_bigint) const {

}

bool BigInt::operator!=(const BigInt &other_bigint) const {

}

std::ostream &operator<<(std::ostream &out, const BigInt &bigint) {
  if (bigint.sign < 0) {
    out << '-';
  }
  for (size_t i = bigint.size; i > 0; --i) {
    out << bigint.data[i - 1];
  }
  return out;
}