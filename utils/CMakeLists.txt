add_library(
    utils
    src/utils/hex.hpp
    src/utils/generalised.hpp
    src/utils/hex.cpp
)

target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(utils PRIVATE constants)
