#pragma once

#include <vector>

#include "header.h"

namespace HTTP {
  class Response {

    public:
      Response(void);

    public:
      int get_status(void) const;
      std::vector<HTTP::Header> get_headers(void) const;

    private:
      int status;
      std::vector<HTTP::Header> headers = {};
  };
}