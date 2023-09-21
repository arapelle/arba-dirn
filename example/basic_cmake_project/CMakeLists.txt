cmake_minimum_required(VERSION 3.26)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package arba-dirn:
find_package(arba-dirn 0.3.0 CONFIG REQUIRED)
# Use arba-dirn release header-only target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba-dirn)
