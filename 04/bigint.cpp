#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

#include "bigint.hpp"

BigInt::BigInt(int value) {
  size_t capacity = 1;
  data = new char [capacity];
  size = 0;
  sign = (value >= 0) ? 1 : -1;

  if (value == 0) {
    data = new char [1];
    data[0] = '0';
    size = 1;

    return;
  }

  value = std::abs(value);

  while (value > 0) {
    if (size == capacity) {
      capacity *= 2;
      char *new_data = new char [capacity];
      for (size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
      }
      delete [] data;
      data = new_data;
    }
    data[size] = value % 10 + '0';
    value /= 10;
    size++;
  }
  if (size != capacity) {
    char *new_data = new char [size];
    for (size_t i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }
    delete [] data;
    data = new_data;
  }
}

BigInt::BigInt(const std::string &data_, size_t size_) {
  if (data_.empty() && size_ < 0) {
    throw std::runtime_error("Error: not a number!");
  }

  if (data_.empty()) {
    size = size_;
    if (size == 0) {
      data = new char [1];
      data[0] = '0';
    } else {
      data = new char [size];
    }
    return;
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

    data[size - 1 - i + offset] = data_[i];
  }
}

BigInt::BigInt(const BigInt &other_bigint) : sign(other_bigint.sign), 
                                             size(other_bigint.size) {
  data = new char [size];

  for (size_t i = 0; i < size; ++i) {
    data[i] = other_bigint.data[i];
  }
}

BigInt::BigInt(BigInt &&other_bigint) : data(other_bigint.data),
                                        sign(other_bigint.sign), 
                                        size(other_bigint.size) {
  other_bigint.data = nullptr;
  other_bigint.size = 0;
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

  other_bigint.data = nullptr;
  other_bigint.size = 0;

  return *this;
}

BigInt::~BigInt() {
  if (data != nullptr) {
    delete [] data;
  }
  size = 0;
}


BigInt BigInt::operator+(const BigInt &other_bigint) const {
  if (sign != other_bigint.sign) {
    return *this - (-other_bigint);
  }

  BigInt res("", std::max(size, other_bigint.size));
  res.sign = sign;
  int dec = 0;

  for (size_t i = 0; i < res.size; ++i) {
    int first_dig = (i < size) ? (data[i] - '0')  : 0;
    int second_dig = (i < other_bigint.size) ? 
                     (other_bigint.data[i] - '0') : 0;
    
    int next_dig = first_dig + second_dig + dec;  
    res.data[i] = '0' + next_dig % 10;

    dec = next_dig / 10;
  }

  if (dec == 1) {
    res.size++;
    char *new_res = new char [res.size];
    new_res[res.size - 1] = '1';
    for (size_t i = 0; i < res.size - 1; ++i) {
      new_res[i] = res.data[i];
    }
    delete [] res.data;
    res.data = new_res;
  }
  
  return res;
}

BigInt BigInt::operator-(const BigInt &other_bigint) const {
  if (sign != other_bigint.sign) {
    return *this + (-other_bigint);
  }

  int comp_res = this->compare_abs(other_bigint);
  
  if (comp_res == 0) {
    return BigInt("0");
  }

  bool reverse = (comp_res == 1);


  BigInt res("", std::max(size, other_bigint.size));
  res.sign = ((sign == 1) == reverse) ? -1 : 1;

  int dec = 0;
  int leading_zero_counter = 0;
  for (size_t i = 0; i < res.size; ++i) {
    int first_dig = (i < size) ? (data[i] - '0')  : 0;
    int second_dig = (i < other_bigint.size) ? 
                     (other_bigint.data[i] - '0') : 0;
    
    int next_dig = dec + ((reverse) ? second_dig - first_dig : first_dig - second_dig);

    leading_zero_counter = (next_dig == 0) ? leading_zero_counter + 1 : 0;

    if (next_dig < 0) {
      dec = -1;
      next_dig += 10;
    } else {
      dec = 0;
    }

    res.data[i] = '0' + next_dig % 10;
  }

  if (leading_zero_counter != 0) {
    res.size -= leading_zero_counter;
    char *new_res = new char [res.size];

    for (size_t i = 0; i < res.size; ++i) {
      new_res[i] = res.data[i];
    }
    delete [] res.data;
    res.data = new_res;
  }
  
  return res;
}

BigInt BigInt::operator*(int digit) const {
  BigInt part_res("", size);

  int dec = 0;
  for (size_t i = 0; i < size; ++i) {
    int next_dig = digit * (data[i] - '0');
    part_res.data[i] = '0' + (next_dig % 10 + dec);
    dec = next_dig / 10;
  }

  if (dec > 0) {
    part_res.size++;
    char *new_res = new char [part_res.size];
    new_res[part_res.size - 1] = dec + '0';
    for (size_t i = 0; i < part_res.size - 1; ++i) {
      new_res[i] = part_res.data[i];
    }
    delete [] part_res.data;
    part_res.data = new_res;
  }

  return part_res;
}

BigInt BigInt::operator*(const BigInt &other_bigint) const {
  BigInt res("0");

  for (size_t i = 0; i < other_bigint.size; ++i) {
    size_t cur_size = size + i;
    BigInt cur_part("", cur_size);
    
    for (size_t k = 0; k < cur_size; ++k) {
      cur_part.data[k] = (cur_size - k <= size) ? data[k - i] : '0';
    }

    res = res + cur_part * (other_bigint.data[i] - '0');
  }

  res.sign = sign * other_bigint.sign;

  return res;
}

BigInt BigInt::operator-() const {
  BigInt res(*this);
  res.sign *= -1;
  return res;
}

int BigInt::compare_abs(const BigInt &other_bigint) const {
  if (other_bigint.size > size) {
    return 1;
  }
  if (other_bigint.size < size) {
    return -1;
  }

  for (size_t i = size; i > 0; --i) {
    if (other_bigint.data[i - 1] > data[i - 1]) {
      return 1;
    } 
    if (other_bigint.data[i - 1] < data[i - 1]) {
      return -1;
    }
  }
  return 0;
}

bool BigInt::operator<(const BigInt &other_bigint) const {
  if (sign > other_bigint.sign) {
    return false;
  }

  if (sign < other_bigint.sign) {
    return true;
  }
  
  return this->compare_abs(other_bigint) * sign == 1;
}

bool BigInt::operator<=(const BigInt &other_bigint) const {
  if (sign > other_bigint.sign) {
    return false;
  }

  if (sign < other_bigint.sign) {
    return true;
  }
  return this->compare_abs(other_bigint) * sign != -1;
}

bool BigInt::operator>(const BigInt &other_bigint) const {
  if (sign < other_bigint.sign) {
    return false;
  }

  if (sign > other_bigint.sign) {
    return true;
  }

  return this->compare_abs(other_bigint) * sign == -1;
}

bool BigInt::operator>=(const BigInt &other_bigint) const {
  if (sign < other_bigint.sign) {
    return false;
  }

  if (sign > other_bigint.sign) {
    return true;
  }

  return this->compare_abs(other_bigint) * sign <= -1;
}

bool BigInt::operator==(const BigInt &other_bigint) const {
  if (sign != other_bigint.sign) {
    return false;
  }

  return this->compare_abs(other_bigint) == 0;
}

bool BigInt::operator!=(const BigInt &other_bigint) const {
  if (sign != other_bigint.sign) {
    return true;
  }

  return this->compare_abs(other_bigint) != 0;
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