find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
    HEADER_ONLY ${PROJECT_NAME}
    SOURCES
        directions4_tests.cpp
        neighbourhood_tests.cpp
)
