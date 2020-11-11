#pragma once

#include <iostream>

#include "error.hpp"

class Deserializer {
    static constexpr char Separator = ' ';
public:
    explicit Deserializer(std::istream& inp_);

    template <class ArgT>
    Error load_arg(ArgT &&arg);
    
    template <class ArgT, class... ArgsT>
    Error load_arg(ArgT &&arg, ArgsT &&...args);

    template <class T>
    Error load(T& object);

    template <class... ArgsT>
    Error operator()(ArgsT &&...args);
    
private:
    std::istream& inp;
};

#include "deserializer.tpp"