#pragma once

#include <sstream>
#include <stdexcept>
#include <string>

class NotEnoughArgsError : public std::runtime_error {
 public:
  NotEnoughArgsError(const char* file_, int line_, 
                     const std::string& mes_) : std::runtime_error(mes_) {
    std::ostringstream error_mes;
    error_mes << file_ << "::" << line_ << "::" << mes_;
    mes = error_mes.str();
  }
  const char* what() const throw() {
    return mes.c_str();
  }
 private:
  std::string mes;
};

class BraceUsageError : public std::runtime_error {
 public:
  BraceUsageError(const char* file_, int line_, 
                  const std::string& mes_) : std::runtime_error(mes_) {
    std::ostringstream error_mes;
    error_mes << file_ << "::" << line_ << "::" << mes_;
    mes = error_mes.str();
  }
  const char* what() const throw() {
    return mes.c_str();
  }
 private:
  std::string mes;
};

class ArgumentError : public std::runtime_error {
 public:
  ArgumentError(const char* file_, int line_, 
                     const std::string& mes_) : std::runtime_error(mes_) {
    std::ostringstream error_mes;
    error_mes << file_ << "::" << line_ << "::" << mes_;
    mes = error_mes.str();
  }
  const char* what() const throw() {
    return mes.c_str();
  }
 private:
  std::string mes;
};

class TooManyArgsError : public std::runtime_error {
 public:
  TooManyArgsError(const char* file_, int line_, 
                     const std::string& mes_) : std::runtime_error(mes_) {
    std::ostringstream error_mes;
    error_mes << file_ << "::" << line_ << "::" << mes_;
    mes = error_mes.str();
  }
  const char* what() const throw() {
    return mes.c_str();
  }
 private:
  std::string mes;
};