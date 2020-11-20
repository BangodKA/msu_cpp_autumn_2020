#include <cctype>
#include <sstream>
#include <string>
#include <tuple>

#include "exceptions.hpp"

template <typename ArgT>
void GetArg(std::ostream& res, long needed_num, long cur_num, const ArgT &arg) {
  if (needed_num != cur_num) {
    throw NotEnoughArgsError(__FILE__, __LINE__, "Error: Not enough arguments in format");
  }
  res << arg;
}

template <typename ArgT, typename... ArgsT>
void GetArg(std::ostream& res, long needed_num, long cur_num, const ArgT &arg, const ArgsT &...args) {
  if (needed_num == cur_num) {
    res << arg;
  } else {
    GetArg(res, needed_num, cur_num + 1, args...);
  }
}

template <typename... ArgsT>
std::string format(const std::string &inp, const ArgsT &...args) {
  // args_amount = std::forward_as_tuple(args...).size();
  std::ostringstream res;
  bool arg_place = false;
  std::string arg_num;

  for (const char symb : inp) {
    if (symb == '{') {
      arg_place = true;
    } else if (arg_place) {
      if (std::isdigit(symb)) {
        arg_num += symb;
      } else if (symb == '}') {
        arg_place = false;
        if (arg_num.size() > 0) {
          try {
            GetArg(res, std::stoul(arg_num), 1, args...);
            arg_num.clear();
          } catch (const std::logic_error&) {
            throw TooManyArgsError(__FILE__, __LINE__, "Error: too big arg number");
          }
        } else {
          throw BraceUsageError(__FILE__, __LINE__, "Error: no argument inside '{}'");
        }
      } else {
        throw ArgumentError(__FILE__, __LINE__, "Error: argument must be a number");
      }
    } else if (symb == '}') {
      throw BraceUsageError(__FILE__, __LINE__, "Error: '}' usage is inappropriate");
    } else {
      res << symb;
    }
  }
  if (arg_place) {
    throw BraceUsageError(__FILE__, __LINE__, "Error: '{' usage is inappropriate");
  }
  return res.str();
}