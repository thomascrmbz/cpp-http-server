#pragma once

namespace HTTP {
  class Server {

    public:
      Server(void);

    public:
      void listen(int port) const;
  };
}