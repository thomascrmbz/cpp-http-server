#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <thread>

#include "http.h"
#include "response.h"
#include "request.h"

using namespace HTTP;

Server::Server(void) {
  
}

void Server::listen(int port) const {
  int socket;
  struct sockaddr_in address;
  int opt = 1;

  if ((socket = ::socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(1);
  }

  if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(1);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(0);
  }
  if (::listen(socket, 3) < 0) {
    perror("listen");
    exit(0);
  }

  while (true) {
    int new_socket;
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);
    char buffer[1024] = {0};

    if ((new_socket = accept(socket, (struct sockaddr *) &addr, (socklen_t*) &addrlen)) <0) {
      perror("accept");
      exit(0);
    }

    read(new_socket, buffer, 1024);
    Request request(buffer);


    auto f = [](int socket) {
      std::string text = "HTTP/1.1 200 OK\n\nHello World!";
      send(socket, text.c_str(), text.length(), 0);
      printf("Response message sent\n\n");
      close(socket);
    };

    std::thread th(f, new_socket);
    th.detach();
    
  }
}