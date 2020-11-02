#pragma once

#include <string>

namespace HTTP {

  class Header {

    public:
      Header(std::string key, std::string value);

    private:
      std::string key;
      std::string value;

  };

};