#pragma once

#include <iostream>

#include "../custom_vector.hpp"

template<typename T>
bool operator==(const std::vector<T>& std_v, const Vector<T>& my_v) {
    if (std_v.size() != my_v.Size()) {
        return false;
    }
    for (size_t i = 0; i < std_v.size(); ++i) {
        if (std_v[i] != my_v[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const Vector<T>& v) {
    s << v.Size() << "::[";
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
    s << v.size() << "::[";
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

template<typename T>
void output_res(std::ostream& my_out, std::ostream& std_out,
                const Vector<T>& my_vec, const std::vector<T>& std_vec) {
  my_out << my_vec << std::endl;
  std_out << std_vec << std::endl;
}