#include <http.h>

int main() {

  HTTP::Server server;

  server.handle = [](HTTP::Request req, HTTP::Response res) {
    std::vector<HTTP::Header> headers;
    headers.push_back(HTTP::Header("Server", "Basic HTTP Server"));

    res.set_headers(headers);
    res.set_content("Hello World!");
    res.send();
    res.close();
  };

  server.listen(8080);

  return 0;
}