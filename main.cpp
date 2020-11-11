#include "src/http.h"
#include <iostream>

int main() {
  std::cout << "HTTP Server" << std::endl;

  HTTP::Server server;

  server.handle = [](HTTP::Request req, HTTP::Response res) {
    std::cout << req.get_method() << " " << req.get_path() << std::endl;

    res.set_content("Hello World from main.cpp!");
    res.send();
  };

  server.listen(8080);

  return 0;
}