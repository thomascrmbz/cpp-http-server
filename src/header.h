#pragma once

#include <string>

namespace HTTP {

  class Header {

    public:
      Header(std::string key, std::string value);

    public:
      std::string get_key(void) const;
      std::string get_value(void) const;

    public:
      void set_key(std::string key);
      void set_value(std::string value);

    public:
      std::string to_string(void) const;

    private:
      std::string key;
      std::string value;

  };

};