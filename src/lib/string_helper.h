#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstring>

class StringHelper {

  public:
    std::vector<std::string> split(std::string str) const;
    std::vector<std::string> buffer_to_vector(char* buffer) const;

};

std::vector<std::string> StringHelper::split(std::string str) const {
  std::string buffer;
  std::stringstream ss(str);
  std::vector<std::string> result;

  while (ss >> buffer) result.push_back(buffer);

  return result;
}

std::vector<std::string> StringHelper::buffer_to_vector(char* buffer) const {
  std::vector<std::string> lines;
  std::stringstream ss;

  for (int i = 0; i < std::strlen(buffer); i++) {
    if (buffer[i] == '\n') {
      lines.push_back(ss.str());
      ss.clear();
    } else ss << buffer[i];
  }

  return lines;
}