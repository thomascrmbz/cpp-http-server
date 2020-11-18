#pragma once

#include <vector>

#include "header.h"

namespace HTTP {
  class Request {

    public:
      Request(char buffer[1024]);

    public:
      std::string get_method(void) const;
      std::string get_path(void) const;
      std::string get_version(void) const;
      std::vector<HTTP::Header> get_headers(void) const;
      std::vector<std::string> get_content(void) const;
      HTTP::Header get_header(std::string key) const;

    private:
      std::string method;
      std::string path;
      std::string version;
      std::vector<HTTP::Header> headers = {};
      std::vector<std::string> content = {};
  };
}