#ifndef UUID_H
#define UUID_h

#include <string>

class UUID {
  public:
    UUID();

    std::string generate_id();
};

#endif