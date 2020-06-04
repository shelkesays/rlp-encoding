add_library(
    rlp
    rlpstring.cpp
    rlplist.cpp
    rlpencode.cpp
    rlpdecode.cpp
)

target_include_directories(rlp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_definitions(say-hello PUBLIC UTILS_VERSION=4)
