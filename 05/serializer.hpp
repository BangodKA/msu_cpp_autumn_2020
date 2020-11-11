#pragma once

#include <iostream>

#include "error.hpp"

class Serializer {
  static constexpr char Separator = ' ';
 public:
  explicit Serializer(std::ostream &out_);

  template <class ArgT>
  Error save_arg(ArgT &&arg);
  
  template <class ArgT, class... ArgsT>
  Error save_arg(ArgT &&arg, ArgsT &&...args);

  template <class T>
  Error save(T& object);

  template <class... ArgsT>
  Error operator()(ArgsT &&...args);
    
 private:
  template <class ArgT>
  bool CheckIfBool(ArgT &&);
  std::ostream& out;
};

#include "serializer.tpp"