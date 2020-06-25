set(SOURCE main.cpp)
add_executable(vnmain ${SOURCE})

target_link_libraries(vnmain PRIVATE constants utils rlp)
