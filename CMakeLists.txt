# Verified RLP: Recursive Length Prefix encoding/decoding implementation in C++.
# Copyright 2019-2020 Verified Networks (Kallol Borah).
# Licensed under the MIT License. See the LICENSE file.

# This is a CMake for verified-rlp
cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)

# Include Hunter configurations
Include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.279.tar.gz"
    SHA1 "0a8ede485c3e9c1ceed8ccb989ab6c0aba1f4db7"
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add tests directory for performing unit testing
set(PACKAGE_TEST "Build the tests" ON)

project(librlpencoding VERSION 0.1.0)

######################################################################################
# Dependencies
# Boost Header only library
hunter_add_package(Boost) # Add `COMPONENTS regex` if required
find_package(Boost CONFIG REQUIRED) # Add `regex` if regex added to component

######################################################################################
# Create Target and set properties
set(SOURCES
    src/utils/hex.cpp
    src/rlp/items/rlpstring.cpp
    src/rlp/items/rlplist.cpp
    src/rlp/codec/rlpencode.cpp
    src/rlp/codec/rlpdecode.cpp
)
add_library(rlpencoding "${SOURCES}")

# Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(RLPEncoding::rlpencoding ALIAS rlpencoding)

# Set target properties
target_include_directories(rlpencoding
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(rlpencoding PRIVATE cxx_auto_type)
target_compile_options(rlpencoding PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Wall -Wextra -Wpedantic>)

target_link_libraries(rlpencoding
    PUBLIC
        Boost::boost
    # PRIVATE
    #     Boost::regex
    # INTERFACE
    #     Boost::boost
)

######################################################################################
# Installation instructions

######################################################################################
# Exporting from the build tree

######################################################################################
# Move to bin directory
set_target_properties(rlpencoding
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

######################################################################################
# Add tests
if(PACKAGE_TEST)
    # Google Test library
    hunter_add_package(GTest)
    find_package(GTest CONFIG REQUIRED)
    # Prevent GoogleTest from overriding our compiler/linker options when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    enable_testing()
    include(GoogleTest)

    add_subdirectory(tests)
endif()

######################################################################################
# Example
add_subdirectory(examples)
