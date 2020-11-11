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

std::string Request::get_method(void) const {
  return this->method;
}

std::string Request::get_path(void) const {
  return this->path;
}

std::string Request::get_version(void) const {
  return this->version;
}

std::vector<HTTP::Header> Request::get_headers(void) const {
  return this->headers;
}