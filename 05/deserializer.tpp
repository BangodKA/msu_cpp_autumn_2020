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
      return HandleError();
    }
  } else if (std::is_same<uint64_t&, ArgT>::value) {
    try {
      arg = std::stoull(next_var);
    } catch (const std::out_of_range&) {
      return HandleError();
    } catch (const std::invalid_argument&) {
      return HandleError();
    }
  } else {
    inp.clear();
    return Error::CorruptedArchive;
  }
  return Error::NoError;
}

template <class ArgT, class... ArgsT>
Error Deserializer::load_arg(ArgT &&arg, ArgsT &&...args) {
  Error res = load_arg(std::forward<ArgT>(arg));
  if (res != Error::NoError) {
    return res;
  }
  return load_arg(std::forward<ArgsT>(args)...);
}

template <class T>
Error Deserializer::load(T& object) {
  return object.serialize(*this);
}

template <class... ArgsT>
Error Deserializer::operator()(ArgsT &&...args) {
  return load_arg(std::forward<ArgsT>(args)...);
}

Error Deserializer::HandleError() {
  inp.clear();
  return Error::CorruptedArchive;
}