#pragma once

#include <functional>
#include "response.h"
#include "request.h"

namespace HTTP {
  class Server {

    public:
      Server(void);

    public:
      void listen(int port) const;
      std::function<void(Request, Response)> handle;
  };
}