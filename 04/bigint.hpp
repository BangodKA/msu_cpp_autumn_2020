#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <string>

#define MAX_DIG_AMOUNT (std::numeric_limits<unsigned int>::digits10 - 1)
class BigInt {
 public:
  BigInt(int value);
  BigInt(const std::string &data_ = "", size_t size_ = 1);
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

  void ReverseNumber(const std::string not_reversed, size_t offset);
  int SubstractWithLeading(const BigInt &lhs, const BigInt &rhs, bool reverse);
  void Realloc(int capacity = -1);
  void AddExtraPart(unsigned int dec);
  void MulTen();
  BigInt operator*(int digit) const;
  int CompareAbs(const BigInt &other_bigint) const;
  
  unsigned int *data;
  int sign = 1;
  size_t size;

  const unsigned int max_ten_pow = std::pow(10, MAX_DIG_AMOUNT);
};