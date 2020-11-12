#include "response.h"

#include <sys/socket.h>
#include <unistd.h>

using namespace HTTP;

Response::Response(int socket) {
  this->socket = socket;
  this->set_content("Hello World!");
  this->set_status("200 OK");
}

std::string Response::get_status(void) const {
  return this->status;
}

std::string Response::get_content(void) const {
  return this->content;
}

std::vector<HTTP::Header> Response::get_headers(void) const {
  return this->headers;
}

void Response::set_content(std::string content) {
  this->content = content;
}

void Response::set_headers(std::vector<HTTP::Header> headers) {
  this->headers = headers;
}

void Response::set_status(std::string status) {
  this->status = status;
}

std::string Response::to_string(void) const {
  return "HTTP/1.1 " + this->get_status() + "\n\n" + this->content + "\n";
}

void Response::send(void) const {
  ::send(this->socket, this->to_string().c_str(), this->to_string().length(), 0);
  ::close(this->socket);
}