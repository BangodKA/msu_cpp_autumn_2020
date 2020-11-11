#include <iostream>
#include <type_traits>

Serializer::Serializer(std::ostream &out_) : out(out_) {}

template <class ArgT>
Error Serializer::save_arg(ArgT &&arg) {
  std::stringstream next_var;
  next_var << arg;
  if (std::is_same<bool, ArgT>::value || 
      std::is_same<bool&, ArgT>::value ||
      std::is_same<const bool&, ArgT>::value) {
    if (next_var.str() == "1") {
      out << "true";
    } else {
      out << "false";
    }
  } else {
    out << arg;
  }
  return Error::NoError;
}

template <class ArgT, class... ArgsT>
Error Serializer::save_arg(ArgT &&arg, ArgsT &&...args) {
  save_arg(std::forward<ArgT>(arg));
  out << Separator;
  return save_arg(std::forward<ArgsT>(args)...);
}

template <class T>
Error Serializer::save(T& object) {
  return object.serialize(*this);
}

template <class... ArgsT>
Error Serializer::operator()(ArgsT &&...args) {
  return save_arg(args...);
}
