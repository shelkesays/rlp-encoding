# This is a CMake for verified-rlp
cmake_minimum_required(VERSION 3.8.0)

project(verified-rlp VERSION 0.1.0)

# message(STATUS "Name: ${PROJECT_NAME}")
# message(STATUS "Version: ${PROJECT_VERSION}")

add_subdirectory(utils)
add_subdirectory(rlp)
add_subdirectory(main)
