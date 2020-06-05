add_library(
    utils
    src/utils/alias.hpp
    src/utils/constants.hpp
    src/utils/hex.hpp
    src/utils/generalised.hpp
    src/utils/hex.cpp
)

target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# target_compile_definitions(utils PUBLIC UTILS_VERSION=4)
