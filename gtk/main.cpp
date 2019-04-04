#include "headers/application.hpp"

int main(int argc, char* argv[])
{
  auto application = ExampleApplication::create();

  const int status = application->run(argc, argv);
  return status;
}
