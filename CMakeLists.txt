# This is a CMake for rlp

cmake_minimum_required(VERSION 3.8.0)

project(rlp VERSION 0.1.0)
# set(verifiedutils_VERSION_MAJOR 0)
# set(verifiedutils_VERSION_MINOR 1)
# set(verifiedutils_VERSION_PATCH 0)
# set(verifiedutils_VERSION ${verifiedutils_VERSION_MAJOR}.${verifiedutils_VERSION_MINOR}.${verifiedutils_VERSION_PATCH})
# set(PACKAGE_VERSION ${verifiedutils_VERSION})
# set(PROJECT_VERSION ${verifiedutils_VERSION})

# message(STATUS "Name: ${PROJECT_NAME}")
# message(STATUS "Version: ${PROJECT_VERSION}")

add_subdirectory(say-hello)
add_subdirectory(utils)
