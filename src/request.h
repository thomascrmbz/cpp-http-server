#pragma once

#include <vector>

#include "header.h"

namespace HTTP {
  class Request {

    public:
      Request(char buffer[1024]);

    public:
      std::vector<HTTP::Header> get_headers(void) const;

    private:
      std::vector<HTTP::Header> headers = {};
      std::string method;
      std::string path;
      std::string version;
  };
}