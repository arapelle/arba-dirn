cmake_minimum_required(VERSION 3.16)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
# Find package dirn:
find_package(dirn 0.2.0 CONFIG REQUIRED)
# Use dirn release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba::dirn)
# Use dirn release static target:
#target_link_libraries(${PROJECT_NAME} PRIVATE arba::dirn-static)
