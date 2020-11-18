<h1 align="center">
  C++ HTTP-Server
</h1>
<h3 align="center">
  Simple and fast HTTP-Server build on C++11
</h3>

# Getting Started

```c++
#include "http.h"

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
```

## Request

```c++
std::string get_method(void) const;
std::string get_path(void) const;
std::string get_version(void) const;
std::vector<HTTP::Header> get_headers(void) const;
std::vector<std::string> get_content(void) const;
```

## Response

```c++
std::string get_status(void) const;
std::string get_content(void) const;
std::vector<HTTP::Header> get_headers(void) const;

void set_status(std::string status);
void set_content(std::string content);
void set_headers(std::vector<HTTP::Header> headers);

std::string to_string(void) const;
void send(void) const;
void close(void) const;
```

## Header

```c++
Header(std::string key, std::string value);

std::string get_key(void) const;
std::string get_value(void) const;

void set_key(std::string key);
void set_value(std::string value);

std::string to_string(void) const;
```

# License

This project is licensed under the MIT License.
