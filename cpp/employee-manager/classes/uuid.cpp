#include <string>

#include "../headers/uuid.hpp";

UUID::UUID() {};

unsigned long int UUID::generate_id() {
  const std::string chars {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

};