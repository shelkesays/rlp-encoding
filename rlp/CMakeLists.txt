add_library(
    rlp
    src/items/rlpstring.hpp
    src/items/rlpstring.cpp
    src/items/rlplist.hpp
    src/items/rlplist.cpp
    src/codec/rlpencode.hpp
    src/codec/rlpencode.cpp
    src/codec/rlpdecode.hpp
    src/codec/rlpdecode.cpp
)

target_include_directories(rlp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

