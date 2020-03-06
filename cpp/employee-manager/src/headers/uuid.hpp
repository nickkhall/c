#ifndef UUID_H
#define UUID_H

#include <string>

class UUID {
  public:
    UUID();

    std::string generate_id();
};

#endif
