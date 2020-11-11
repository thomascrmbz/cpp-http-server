#include "response.h"

#include <sys/socket.h>
#include <unistd.h>

using namespace HTTP;

Response::Response(int socket) {
  this->socket = socket;
  this->content = "Hello World!";
}

int Response::get_status(void) const {
  return this->status;
}

std::vector<HTTP::Header> Response::get_headers(void) const {
  return this->headers;
}

void Response::set_content(std::string content) {
  this->content = content;
}

std::string Response::to_string(void) const {
  return "HTTP/1.1 200 OK\n\n" + content + "\n";
}

void Response::send(void) const {
  ::send(this->socket, this->to_string().c_str(), this->to_string().length(), 0);
  ::close(this->socket);
}