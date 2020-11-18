#pragma once

#include <vector>

#include "header.h"

namespace HTTP {
  class Response {

    public:
      Response(int socket);

    public:
      std::string get_status(void) const;
      std::string get_content(void) const;
      std::vector<HTTP::Header> get_headers(void) const;
      int _get_socket(void) const;

    public:
      void set_status(std::string status);
      void set_content(std::string content);
      void set_headers(std::vector<HTTP::Header> headers);

    public:
      std::string to_string(void) const;

    public:
      void send(void) const;
      void close(void) const;

    private:
      int socket;
      std::string status;
      std::string content;
      std::vector<HTTP::Header> headers = {};
  };
}