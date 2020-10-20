#include <cstdint>
#include <iostream>
#include <string>

#include "parser.hpp"


TokenParser::TokenParser(const std::string& data_) : data(data_) {}

void TokenParser::SetStartCallback(ParseProcess StartCallback_) {
  StartCallback = StartCallback_;
}
void TokenParser::SetDigitTokenCallback(ProcessDigitToken DigitTokenCallback_) {
  DigitTokenCallback = DigitTokenCallback_;
}
void TokenParser::SetStringTokenCallback(ProcessStringToken StringTokenCallback_) {
  StringTokenCallback = StringTokenCallback_;
}
void TokenParser::SetEndCallback(ParseProcess EndCallback_) {
  EndCallback = EndCallback_;
}

std::string TokenParser::Parse() {
  StartCallback();

  bool is_digit_token = true;
  std::string current_string_token;

  for (const char symbol : data + '\n') {

    if (symbol != ' ' and symbol != '\t' and 
        symbol != '\n' and symbol != '\r') {
      current_string_token += symbol;
      if (is_digit_token) {
        if (symbol < '0' or symbol > '9') {
          is_digit_token = false;
        }
      }
    } else if (!current_string_token.empty()) {
      if (is_digit_token) {
        DigitTokenCallback(std::stoull(current_string_token));
      } else {
        StringTokenCallback(current_string_token);
      }
      is_digit_token = true;
      current_string_token.clear();
    }
  }

  EndCallback();

  std::string res = parsing_res.str();
  parsing_res.str("");
  return res;
}

std::ostream& TokenParser::GetStream() {
  return parsing_res;
}