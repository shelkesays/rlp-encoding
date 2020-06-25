# Verified RLP: Recursive Length Prefix encoding/decoding implementation in C++.
# Copyright 2019-2020 Verified Networks (Kallol Borah).
# Licensed under the MIT License. See the LICENSE file.

# This is a CMake for verified-rlp
cmake_minimum_required(VERSION 3.16.3)


# Include Hunter configurations
Include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.259.tar.gz"
    SHA1 "59541baf106b91ae4fec32e6c6b0990d04c7f6be"
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(verified-rlp VERSION 0.1.0)

# message(STATUS "Name: ${PROJECT_NAME}")
# message(STATUS "Version: ${PROJECT_VERSION}")

# Boost Header only library
hunter_add_package(Boost)
find_package(Boost CONFIG REQUIRED)

# Add project specific subdirectories
add_subdirectory(constants)
add_subdirectory(utils)
add_subdirectory(rlp)
add_subdirectory(main)

set(SOURCE rlp.cpp)
add_executable(vnrlp ${SOURCE})

target_link_libraries(vnrlp PRIVATE constants utils rlp)
