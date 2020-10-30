# C++ HTTP-Server

Simple and fast HTTP-Server build on C++

# Getting Started

```c++
#include "http.h"

int main() {

  HTTP::Server server;

  server.listen(8080);

  return 0;
}
```

# License

This project is licensed under the MIT License.