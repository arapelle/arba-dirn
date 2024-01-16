cmake_minimum_required(VERSION 3.26)

# CMAKE INCLUDES

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "arba" BASE_NAME "dirn")
string(TIMESTAMP configure_datetime "%Y%m%d-%H%M%S" UTC)
set_project_semantic_version("0.5.0"
    PRE_RELEASE "dev"
    BUILD_METADATA "${configure_datetime}"
)
project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "C++ library for directions (up, left, down right)..."
        HOMEPAGE_URL "https://github.com/arapelle/arba-dirn"
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}")
include(CTest)

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_BASE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/arba/dirn/d2/dir4/cartographic_directions4.hpp
    include/arba/dirn/d2/dir4/direction4.hpp
    include/arba/dirn/d2/dir4/directions4.hpp
    include/arba/dirn/d2/dir6/horizontal_direction6.hpp
    include/arba/dirn/d2/dir6/horizontal_directions6.hpp
    include/arba/dirn/d2/dir6/vertical_direction6.hpp
    include/arba/dirn/d2/dir6/vertical_directions6.hpp
    include/arba/dirn/d2/dir8/cartographic_directions8.hpp
    include/arba/dirn/d2/dir8/direction8.hpp
    include/arba/dirn/d2/dir8/directions8.hpp
    include/arba/dirn/direction.hpp
    include/arba/dirn/directions.hpp
    include/arba/dirn/directions_decl.hpp
    include/arba/dirn/dual_direction.hpp
    include/arba/dirn/dual_directions.hpp
    include/arba/dirn/dual_directions_decl.hpp
    include/arba/dirn/neighborhood.hpp
)

## Add C++ library
add_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    HEADERS ${headers} ${configured_headers}
    CXX_STANDARD 20
)

## Link C++ targets:
if(NOT TARGET arba-vrsn)
    find_package(arba-vrsn 0.1.0 REQUIRED CONFIG)
endif()
target_link_libraries(${PROJECT_NAME} INTERFACE arba-vrsn)

## Install C++ library
install_cpp_library(
    HEADER_ONLY ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
)

## Install package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE cmake/config/package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME} FILENAME uninstall.cmake)

## Add examples:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_EXAMPLES "Build ${PROJECT_NAME} examples or not" OFF BUILD_arba-arba_EXAMPLES)
if(BUILD_${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(example)
endif()

## Add tests:
option_or_set_ifdef(BUILD_${PROJECT_NAME}_TESTS "Build ${PROJECT_NAME} tests or not" OFF BUILD_arba-arba_TESTS)
if(BUILD_${PROJECT_NAME}_TESTS AND BUILD_TESTING)
    add_subdirectory(test)
endif()
