cmake_minimum_required (VERSION 3.5)

project(ipv4datarep)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")


add_executable(ipv4datarep ${PROJECT_SOURCE_DIR}/ipv4.cpp)