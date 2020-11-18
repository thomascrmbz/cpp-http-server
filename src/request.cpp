#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "request.h"
#include "header.h"
#include "lib/string_helper.h"

using namespace HTTP;

Request::Request(char buffer[1024]) {
  std::vector<std::string> lines = StringHelper().buffer_to_vector(buffer);
  std::vector<std::string> head = StringHelper().split(lines[0]);
  
  this->method = head[0];
  this->path = head[1];
  this->version = head[2];

  int content_index = 0;

  for (int i = 1; i < lines.size(); i++) {
    if (lines[i][0] == '\r') {
      content_index = i + 1;
      break;
    }
    std::vector<std::string> header = StringHelper().split(lines[i]);
    std::string key = header[0];
    key.pop_back();

    std::string value;
    header.erase(header.begin());
    for (const auto &s : header) value += s + " ";
    value.pop_back();

    this->headers.push_back(Header(key, value));
  }

  for (int i = content_index; i < lines.size(); i++) content.push_back(lines[i]);
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

std::vector<std::string> Request::get_content(void) const {
  return this->content;
}

HTTP::Header Request::get_header(std::string key) const {
  for (Header header : this->get_headers()) {
    if (header.get_key() == key) return header;
  }

  return Header("", "");
}