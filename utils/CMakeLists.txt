set(SOURCE main.cpp)
add_executable(verified-utils ${SOURCE})

target_link_libraries(verified-utils PRIVATE say-hello)