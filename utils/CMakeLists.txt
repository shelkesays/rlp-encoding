add_library(
    utils
    src/alias.hpp
    src/constants.hpp
    src/generalised.hpp
    src/hex.hpp
    src/hex.cpp
)

target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
