add_library(
    hello
    src/say-hello/hello.hpp
    src/say-hello/hello.cpp
)

target_include_directories(hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_definitions(hello PUBLIC UTILS_VERSION=4)