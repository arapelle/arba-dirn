find_or_fetch_GTest()

add_cpp_library_basic_tests(GTest::gtest_main
    HEADER_ONLY ${PROJECT_NAME}
    SOURCES
        project_version_tests.cpp
        # dir4:
        directions4_tests.cpp
        # dir6:
        horizontal_directions6_tests.cpp
        vertical_directions6_tests.cpp
        # dir8:
        directions8_tests.cpp
        # neighborhood:
        neighborhood/neighborhood_direction4_tests.cpp
        neighborhood/neighborhood_horizontal_direction6_tests.cpp
        neighborhood/neighborhood_vertical_direction6_tests.cpp
        neighborhood/neighborhood_direction8_tests.cpp
)
