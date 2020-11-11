#include "src/http.h"
#include <iostream>
#include <unistd.h> 

int main() {
  std::cout << "HTTP Server" << std::endl;

  HTTP::Server server;

  server.listen(8080);

  return 0;
}