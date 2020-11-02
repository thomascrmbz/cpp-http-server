#include "response.h"

using namespace HTTP;

Response::Response(void) {
  
}

int Response::get_status(void) const {
  return this->status;
}

std::vector<HTTP::Header> Response::get_headers(void) const {
  return this->headers;
}