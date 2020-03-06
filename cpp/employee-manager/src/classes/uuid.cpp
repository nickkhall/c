#include "../headers/uuid.hpp"

UUID::UUID() {};

std::string UUID::generate_id() {
  const std::string chars {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
  std::string uuid(36, '-');
  int random = 0;

  for (int i = 0; i < 36; i++) {
    if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
      if (random <= 0x02) {
        random = 0x2000000 + (std::rand() * 0x1000000) | 0;
      }

      random >>= 4;
      uuid[i] = chars[(i == 19) ? ((random & 0xf) & 0x3) | 0x8 : random & 0xf];
    }
  }

  return random;
};
