#pragma once

#include <iostream>
#include <string>

template <typename ArgT>
void GetArg(std::ostream& res, long needed_num, long cur_num, const ArgT &arg);

template <typename ArgT, typename... ArgsT>
void GetArg(std::ostream& res, long needed_num, long cur_num, const ArgT &arg, const ArgsT &... args);
  
template <typename... ArgsT>
std::string format(const std::string &inp, const ArgsT &...args);

#include "format.tpp"