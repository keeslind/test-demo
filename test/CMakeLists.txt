add_executable(
        unit_tests
        main.cpp
        example_test.cpp
        forking_test.cpp)

target_link_libraries(
        unit_tests
        gtest_main
        example
)

add_test(
        unit_tests
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
