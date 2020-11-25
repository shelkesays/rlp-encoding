set(EXAMPLE ${CMAKE_CURRENT_SOURCE_DIR}/src/rlp.cpp)

add_executable(vn-rlp "${EXAMPLE}")

target_link_libraries(vn-rlp PUBLIC RLPEncoding::rlpencoding)

set_target_properties(vn-rlp
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/"
)
