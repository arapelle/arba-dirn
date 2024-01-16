cmake_minimum_required(VERSION 3.26)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} basic_cmake_project.cpp)
# Find package arba-dirn:
find_package(arba-dirn 0.5.0 CONFIG REQUIRED)
# Use arba-dirn release header-only target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba-dirn)
