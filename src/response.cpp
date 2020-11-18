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

int Response::_get_socket(void) const {
  return this->socket;
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
  std::string response = "HTTP/1.1 " + this->get_status() + "\n";
  for (HTTP::Header header : this->get_headers()) response += header.to_string() + "\n";
  return response + "\n" + this->content;
}

void Response::send(void) const {
  ::send(this->socket, this->to_string().c_str(), this->to_string().length(), 0);
}

void Response::close(void) const {
  ::close(this->socket);
}