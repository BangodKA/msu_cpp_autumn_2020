#pragma once

#include <iostream>
#include <string>

class BigInt {
 public:
  BigInt(const std::string &data_);
  BigInt(const BigInt &other_bigint);
  BigInt(BigInt &&other_bigint);
  BigInt& operator=(const BigInt &other_bigint);
  BigInt& operator=(BigInt &&other_bigint);
  ~BigInt();

  BigInt operator+(const BigInt &other_bigint) const;
  BigInt operator-(const BigInt &other_bigint) const;
  BigInt operator*(const BigInt &other_bigint) const;
  BigInt operator-() const;

  bool operator<(const BigInt &other_bigint) const;
  bool operator<=(const BigInt &other_bigint) const;
  bool operator>(const BigInt &other_bigint) const;
  bool operator>=(const BigInt &other_bigint) const;
  bool operator==(const BigInt &other_bigint) const;
  bool operator!=(const BigInt &other_bigint) const;
 private:
  friend std::ostream& operator<<(std::ostream &out, const BigInt &bigint);
  
  char *data;
  int sign = 1;
  size_t size;
  size_t capacity;
};