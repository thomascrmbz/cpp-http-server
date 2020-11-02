#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "request.h"
#include "lib/string_helper.h"

using namespace HTTP;

Request::Request(char buffer[1024]) {
  std::vector<std::string> lines = StringHelper().buffer_to_vector(buffer);
  std::vector<std::string> head = StringHelper().split(lines[0]);
  
  this->method = head[0];
  this->path = head[1];
  this->version = head[2];
}