#include "hello.hpp"

#include <iostream>

void hello::say_hello() {
    std::cout << "Hello World from say-hello version " << UTILS_VERSION << std::endl;
}
