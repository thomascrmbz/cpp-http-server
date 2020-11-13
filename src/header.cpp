#include "header.h"

using namespace HTTP;

Header::Header(std::string key, std::string value) {
  this->key = key;
  this->value = value;
}

std::string Header::get_key(void) const {
  return this->key;
}

std::string Header::get_value(void) const {
  return this->value;
}

void Header::set_key(std::string key) {
  this->key = key;
}

void Header::set_value(std::string value) {
  this->value = value;
}

std::string Header::to_string(void) const {
  return this->get_key() + ": " + this->get_value();
}