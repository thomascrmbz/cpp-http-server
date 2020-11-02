#include "header.h"

using namespace HTTP;

Header::Header(std::string key, std::string value) {
  this->key = key;
  this->value = value;
}