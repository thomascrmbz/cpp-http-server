#pragma once

#include <functional>
#include "response.h"
#include "request.h"

namespace HTTP {
  class Server {

    public:
      Server(void);
      Server(bool while_loop);

    public:
      void listen(int port) const;
      std::function<void(Request, Response)> handle = [](HTTP::Request req, HTTP::Response res) {
        res.send();
      };

    private:
      bool while_loop = true;
  };
}