cmake_minimum_required (VERSION 3.5)

project(missingInteger)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(missingInteger ${PROJECT_SOURCE_DIR}/solution.cpp)
