add_library(
    vntest
    src/test.cpp
)

target_include_directories(vntest PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(GoogleTest)
target_link_libraries(vntest PRIVATE constants utils rlp gtest gmock gtest_main)

add_test(
    NAME vntest 
    COMMAND vntest
)
