#include <iostream>
#include <string>

Deserializer::Deserializer(std::istream& inp_) : inp(inp_) {}

template <class ArgT>
Error Deserializer::load_arg(ArgT &&arg) {
  std::string next_var;
  inp >> next_var;
  if (std::is_same<bool&, ArgT>::value) {
    if (next_var == "true") {
      arg = true;
    } else if (next_var == "false") {
      arg = false;
    } else {
      inp.clear();
      return Error::CorruptedArchive;
    }
  } else if (std::is_same<uint64_t&, ArgT>::value) {
    try {
      arg = std::stoll(next_var);
    } catch (const std::exception&) {
      inp.clear();
      return Error::CorruptedArchive;
    }
  } else {
    inp.clear();
    return Error::CorruptedArchive;
  }
  return Error::NoError;
}

template <class ArgT, class... ArgsT>
Error Deserializer::load_arg(ArgT &&arg, ArgsT &&...args) {
  if (load_arg(arg) == Error::CorruptedArchive) {
    return Error::CorruptedArchive;
  }
  return load_arg(args...);
}

template <class T>
Error Deserializer::load(T& object) {
  return object.serialize(*this);
}

template <class... ArgsT>
Error Deserializer::operator()(ArgsT &&...args) {
  return load_arg(args...);
}