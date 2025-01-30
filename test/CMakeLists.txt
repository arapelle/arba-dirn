include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
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
