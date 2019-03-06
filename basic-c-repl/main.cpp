#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

int main(int argc, const char * argv[]) {
    size_t status {0};
    std::string line;

    while (status == 0) {
        std::cout << "root@root > ";
        std::getline(std::cin, line);
        std::istringstream iss(line);

        if (line == "exit") {
            status = 1;
        }

        system(line.c_str());

        std::cout << std::endl;
    }

    return 0;
}
