find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
    HEADER_ONLY ${PROJECT_NAME}
    SOURCES
        project_version_tests.cpp
        directions4_tests.cpp
        neighborhood_tests.cpp
        horizontal_directions6_tests.cpp
        vertical_directions6_tests.cpp
)
