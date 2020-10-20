#pragma once

#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>


class TokenParser {
  using ParseProcess = std::function<void ()>;
  using ProcessDigitToken = std::function<void (uint64_t token)>;
  using ProcessStringToken = std::function<void (std::string &token)>;

 public:
  TokenParser(const std::string& data_);

  void SetStartCallback(ParseProcess);
  void SetDigitTokenCallback(ProcessDigitToken);
  void SetStringTokenCallback(ProcessStringToken);
  void SetEndCallback(ParseProcess);

  std::string Parse();

  std::ostream& GetStream();

 private:
  std::string data;
  std::ostringstream parsing_res;
  ParseProcess StartCallback = [this]() {parsing_res << "\nParsing started!" << std::endl;};
  ParseProcess EndCallback = [this]() {parsing_res << "\nParsing finished!" << std::endl;};

  ProcessDigitToken DigitTokenCallback = [this](uint64_t token) 
                                         {parsing_res << "Found DIGIT token: " << token << std::endl;};
  ProcessStringToken StringTokenCallback = [this](std::string& token) 
                                         {parsing_res << "Found STRING token: " << token << std::endl;};
};