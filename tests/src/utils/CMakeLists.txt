# Add all the unit test cases as one TEST
set(HEX_TESTS 
    hex/emptybyte.cpp 
    hex/isnumeric.cpp
    hex/ishexprefixed.cpp
    hex/inserthexprefix.cpp
    hex/striphexprefix.cpp
    hex/padtoeven.cpp
    hex/ishexstring.cpp
    hex/integertohex.cpp
    hex/hextointeger.cpp
    hex/floattohex.cpp
    hex/hextofloat.cpp
    hex/stringtohex.cpp
    hex/stringtobyte.cpp
)

set(GENERALISED_TESTS
    generalised/getbytes.cpp
)

set(TESTS "${HEX_TESTS};${GENERALISED_TESTS}")

# Generate a test package
package_add_test(utilstest "${TESTS}")

set_target_properties(utilstest
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/tests"
)
