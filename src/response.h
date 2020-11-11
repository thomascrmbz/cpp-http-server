#pragma once

#include <vector>

#include "header.h"

namespace HTTP {
  class Response {

    public:
      Response(int socket);

    public:
      int get_status(void) const;
      std::vector<HTTP::Header> get_headers(void) const;
      std::string to_string(void) const;
      void set_content(std::string content);

    public:
      void send(void) const;

    private:
      int status;
      int socket;
      std::string content;
      std::vector<HTTP::Header> headers = {};
  };
}