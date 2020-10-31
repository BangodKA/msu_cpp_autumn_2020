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

  BigInt operator+(const BigInt &other_bigint);
  BigInt operator-(const BigInt &other_bigint);
  BigInt operator*(const BigInt &other_bigint);
  BigInt operator-();

  bool operator<(const BigInt &other_bigint);
  bool operator<=(const BigInt &other_bigint);
  bool operator>(const BigInt &other_bigint);
  bool operator>=(const BigInt &other_bigint);
  bool operator==(const BigInt &other_bigint);
  bool operator!=(const BigInt &other_bigint);
 private:
  friend std::ostream& operator<<(std::ostream &out, const BigInt &bigint);
  
  char *data;
  int sign;
  size_t size;
  size_t capacity;
};