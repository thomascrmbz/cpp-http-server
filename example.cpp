#include "src/http.h"

int main() {

  HTTP::Server server;

  server.handle = [](HTTP::Request req, HTTP::Response res) {
    res.set_content("Hello World!");
    res.send();
  };

  server.listen(8080);

  return 0;
}